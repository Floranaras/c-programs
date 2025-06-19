#include "head.h"

void initDatabase(databaseType *db)
{
    int i;
    db->teacherCtr = 0;
    // Initialize all subject counters to 0
    for (i = 0; i < MAX_TEACHER; i++) {
        db->teachers[i].subjectsCtr = 0;
    }
}

int isSubjectTaken(databaseType *db, int teacherIndex, String7 courseCode, int section)
{
    int k;
    int found = 0;
    
    // Check if course code + section combination exists for this teacher
    for (k = 0; k < db->teachers[teacherIndex].subjectsCtr && !found; k++) {
        if (strcmp(db->teachers[teacherIndex].subjects[k].courseCode, courseCode) == 0 &&
            db->teachers[teacherIndex].subjects[k].section == section) {
            found = 1;
        }
    }
    return found;
}

void inputSubjects(databaseType *db, int teacherIndex)
{
    String7 courseCode;
    int section;
    int flag = 1;
    int *subCtr = &db->teachers[teacherIndex].subjectsCtr;
    
    printf("\n--- Adding Subjects for %s ---\n", db->teachers[teacherIndex].name);
    
    do {
        printf("Input Course Code (or %s to stop): ", EXIT);
        scanf("%s", courseCode);
        
        if (strcmp(courseCode, EXIT) != 0) {
            // Store course code
            strcpy(db->teachers[teacherIndex].subjects[*subCtr].courseCode, courseCode);
            
            // Get time
            printf("Input Time (HH:MM): ");
            scanf("%s", db->teachers[teacherIndex].subjects[*subCtr].time);
            
            // Get section (keep asking until unique course+section combination)
            do {
                printf("Input Section: ");    
                scanf("%d", &section);
                if (isSubjectTaken(db, teacherIndex, courseCode, section)) {
                    printf("Course %s with section %d is already in this teacher's load. Please try another section.\n", courseCode, section);
                }
            } while (isSubjectTaken(db, teacherIndex, courseCode, section));
            
            // Store the section
            db->teachers[teacherIndex].subjects[*subCtr].section = section;
            
            // Get units
            printf("Input Units: ");
            scanf("%f", &db->teachers[teacherIndex].subjects[*subCtr].units);
            
            (*subCtr)++;
            printf("Subject added successfully!\n\n");
        } else {
            flag = 0;
        }
        
    } while (*subCtr < MAX_SUB && flag);
    
    if (*subCtr >= MAX_SUB) {
        printf("Maximum subjects (%d) reached for this teacher.\n", MAX_SUB);
    }
}

int isFound(databaseType *db, String25 input)
{
    int j = 0;
    int found = 0;
    
    while (j < db->teacherCtr && !found) {
        if (strcmp(input, db->teachers[j].name) == 0) {
            found = 1;
        }
        j++;
    }
    return found;
}

void inputTeacher(databaseType *db)
{
    String25 temp;
    int flag = 1;
    
    printf("\n--- Adding New Teachers ---\n");
    printf("Enter %s as name to stop adding teachers.\n\n", EXIT);
    
    do {
        printf("Input Name: ");
        scanf("%24s", temp);  // Limit input to prevent buffer overflow
        
        if (strcmp(temp, EXIT) == 0) {
            flag = 0;
        } else if (!isFound(db, temp)) {
            // Store teacher name
            strcpy(db->teachers[db->teacherCtr].name, temp);
            
            // Get department
            printf("Input Department: ");
            scanf("%8s", db->teachers[db->teacherCtr].dept);
            
            // Initialize subject counter for this teacher
            db->teachers[db->teacherCtr].subjectsCtr = 0;
            
            // Input subjects for this teacher
            inputSubjects(db, db->teacherCtr);
            
            // Increment teacher counter
            db->teacherCtr++;
            
            printf("Teacher added successfully!\n");
        } else {
            printf("Name already in the records. Please try a different name.\n");    
        }
        
    } while (db->teacherCtr < MAX_TEACHER && flag);
    
    if (db->teacherCtr >= MAX_TEACHER) {
        printf("Maximum teachers (%d) reached in database.\n", MAX_TEACHER);
    }
}

void displayByCourse(databaseType *db)
{
    String7 courseCode;
    int j, k;
    int found = 0;
    
    printf("Input Course Code: ");
    scanf("%s", courseCode);
    
    printf("\n=== %s Classes ===\n", courseCode);
    printf("Teacher\t\tSection\tUnits\n");
    printf("--------------------------------\n");
    
    for (j = 0; j < db->teacherCtr; j++) {
        for (k = 0; k < db->teachers[j].subjectsCtr; k++) {
            if (strcmp(db->teachers[j].subjects[k].courseCode, courseCode) == 0) {
                printf("%s\t\t%d\t%.1f\n", 
                       db->teachers[j].name, 
                       db->teachers[j].subjects[k].section,
                       db->teachers[j].subjects[k].units);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No classes found for course code: %s\n", courseCode);
    }
    printf("\n");
}

void mainMenu(databaseType *db)
{
    char choice;
    
    printf("Welcome to Teacher Database Management System!\n");
    
    do {
        printf("\n=== Teacher Database ===\n");
        printf("1] Input New Teacher\n");
        printf("2] Display Teachers by Course\n");
        printf("x] Exit\n");
        printf("\nEnter choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1': 
                inputTeacher(db); 
                break;
            case '2': 
                displayByCourse(db); 
                break;
            case 'x': 
            case 'X':
                printf("Exiting program...\n");
                break;
            default: 
                printf("Invalid input! Please try again.\n"); 
                break;
        }
    } while (choice != 'x' && choice != 'X');
}
