#include <string.h>
#include <stdlib.h>
#include "grade_school.h"


bool insert_name(char *, const char *);
bool shift_and_insert(student_t *, uint8_t, const char *, long unsigned int, long unsigned int *);


bool insert_name(char * dest, const char *orig) {
    if(!dest || !orig)
        return false;

    if(strlen(orig) < MAX_NAME_LENGTH)
        return strcpy(dest, orig);
    else
        return strncpy(dest, orig, MAX_NAME_LENGTH);
    return false;
}

bool shift_and_insert(student_t *students, uint8_t grade, const char *name, long unsigned int idx, long unsigned int *total_students_n) {
    if(!students || !name || !total_students_n)
        return false;

    /* first check if name is already on this roster */
    student_t *aux_students = students;
    for(;aux_students->name[0] != '\0'; aux_students++) {
        if(!strcmp(aux_students->name, name))
            /* the name is already on this roster */
            return false;

    }
    memmove((void *)&students[idx + 1], (const void *)&students[idx], (*total_students_n - idx) * sizeof(student_t)/sizeof(char));
    *total_students_n = *total_students_n + 1;
    students[idx].grade = grade;
    return insert_name(students[idx].name, name);
}

int init_roster(roster_t *roster) {
    if(!roster)
        return -1;
    
    roster->count = 0;
    for(int i = 0;i < MAX_STUDENTS; i++) {
        roster->students[i].grade = 0xFF;
        roster->students[i].name[0] = '\0';
    }
    return 0;
}

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
    if(!roster || !name)
        return false;

    if(roster->count < MAX_STUDENTS-1)
        for(long unsigned int idx = 0; idx <= roster->count; idx++) {
            /* Pseudo code
                if grade is bigger han student[i].grade
                    break;
                if grade is less than student[i].grade
                    shift and insert
                if grade is i
                    if name is less than name student[i].grade
                        shift and insert
                    else if name is bigger than name student[i].grade
                        break
                    else if name is name
                        return false
            */
            if(grade > roster->students[idx].grade)
                continue;
            if(grade < roster->students[idx].grade)
                return shift_and_insert(roster->students, grade, name, idx, &roster->count);
            if(grade == roster->students[idx].grade) {
                int cmp = strcmp(roster->students[idx].name, name);
                if(cmp > 0)
                    return shift_and_insert(roster->students, grade, name, idx, &roster->count);
                else if (cmp < 0)
                    continue;
                else /* the name is repeated - or student is already in the roster */
                    /* one student cannot be part of two grades */
                        return false;
            }
        }

    return false;
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade) {
    if(!roster)
        exit(-1);
    
    roster_t roster_ret;
    init_roster(&roster_ret);

    for(unsigned int idx = 0; idx <= roster->count; idx++) {
        if(roster->students[idx].grade == desired_grade) {
            memcpy(roster_ret.students[roster_ret.count].name, roster->students[idx].name, MAX_NAME_LENGTH);
            roster_ret.students[roster_ret.count++].grade = desired_grade;
        }
    }

    return roster_ret;
}
