Student Management System (C)

A simple command-line Student Management System written in C, using structs, dynamic memory allocation, and file I/O for data persistence.

Features
Add Student — auto-generated unique ID, input for name, surname, major, and GPA
Delete Student — remove a student by ID
Show Students — display all students in a readable list
Update Student — modify an existing student's details by ID
Exit — safely closes files and frees allocated memory

All student records are stored in Students.txt and persist between program runs. The file is loaded automatically on startup and rewritten whenever a delete or update occurs.

Project Structure
.
├── main.c              # Program entry point and menu loop
├── student.c           # Core logic: list management, file I/O, CRUD operations
├── Student_manager.h   # Struct definitions and function prototypes
└── Students.txt         # Data file (created automatically on first run)
Data Format

Each line in Students.txt represents one student, with fields separated by |:

id|name|surname|major|gpa

Example:

1|Ali|Mammadov|Computer Science|3.75
How It Works
Dynamic array: Students are stored in a StudentList struct containing a pointer (Student *data), a count, and a capacity. The array grows automatically via realloc when it fills up (ensureCapacity).
ID generation: New students receive max(existing IDs) + 1, preventing duplicate IDs.
Input validation: Menu choices and GPA input are read with fgets + strtol/strtof (not scanf) to safely reject non-numeric input without crashing.
File persistence:
addStudent appends a new record directly to the file ("a" mode).
deleteStudent and updateStudent modify the in-memory list, then call rewriteFile to rewrite the entire file ("w" mode), since individual lines can't be edited in place.
Build & Run
Linux / macOS
bash
gcc -Wall -Wextra -std=c99 -g -o student_manager main.c student.c
./student_manager
Windows (with MinGW/gcc installed)
powershell
gcc -Wall -Wextra -std=c99 -g -o student_manager.exe main.c student.c
.\student_manager.exe
Menu
===== Telebe Idareetme Sistemi =====
1. Telebe elave et
2. Telebeni sil
3. Telebelerin siyahisini goster
4. Telebe melumatlarini yenile
5. Cixis
Notes
Memory allocated with malloc/realloc is freed on exit (freeList) to avoid memory leaks.
All open files are properly closed with fclose after each read/write operation.
Field values containing | are not currently sanitized — avoid using | in name/surname/major input.