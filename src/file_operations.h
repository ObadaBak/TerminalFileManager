#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void creat_f(const char* path);     // Create a file
void unlink_f(const char* path);   // Delete a file
void open_f(const char* path);     // Open a file
void read_f(const char* path);     // Read data from a file
void write_f(const char* path, const char* data); // Write data to a file
void rename_f(const char* source, const char* destination);


#endif