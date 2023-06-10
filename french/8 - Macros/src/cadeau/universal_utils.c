
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#include "universal_utils.h"

/**
 * @brief This function initializes the main program by
 * printing the header
 * 
 * @param header	The header to print
 * 
 * @return void
*/
void mainInit(char* header) {

	// Launch empty powershell command on Windows,
	// it's a trick to get ANSI colors in every terminal for Windows 10
	#ifdef _WIN32
		system("powershell -command \"\"");
	#endif

	// Print the header
	printf("\n---------------------------\n");
	INFO_PRINT("%s", header);
}


/**
 * @brief This function write a string to a file
 * depending on the mode (append or overwrite).
 * 
 * @param filename		Name of the file to write
 * @param content		Content to write
 * @param size			Size of the content
 * @param mode			Mode of writing (O_APPEND or O_TRUNC)
 * 
 * @return int	0 if success, -1 otherwise
 */
int writeEntireFile(char* path, char* content, int size, int mode) {

	// Open the file
	int fd = open(path, O_WRONLY | O_CREAT | mode, 0644);
	ERROR_HANDLE_INT_RETURN_INT(fd, "writeEntireFile(): Cannot open file '%s'\n", path);

	// Write the file
	int written_size = write(fd, content, size);
	if (written_size == -1) close(fd);
	ERROR_HANDLE_INT_RETURN_INT(written_size, "writeEntireFile(): Cannot write to file '%s'\n", path);

	// Close the file
	close(fd);

	// Return
	return 0;
}


/**
 * @brief This function read a file and return its content as a string.
 * 
 * @param filename Name of the file to read
 * 
 * @return char*	Content of the file as a string if success, NULL otherwise
 */
char* readEntireFile(char* path) {
	
	// Open the file
	int fd = open(path, O_RDONLY);
	ERROR_HANDLE_INT_RETURN_NULL(fd, "readEntireFile(): Cannot open file '%s'\n", path);

	// Get the size of the file
	size_t size = get_file_size(fd);

	// Allocate memory for the file content
	char* buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL) close(fd);
	ERROR_HANDLE_PTR_RETURN_NULL(buffer, "readEntireFile(): Cannot allocate memory for file '%s'\n", path);

	// Read the file
	int read_size = read(fd, buffer, size);
	if (read_size == -1) close(fd);
	ERROR_HANDLE_INT_RETURN_NULL(read_size, "readEntireFile(): Cannot read file '%s'\n", path);

	// Close the file
	close(fd);

	// Add a null character at the end of the buffer
	buffer[read_size] = '\0';

	// Return the file content
	return buffer;
}

#define GET_LINE_BUFFER_SIZE 16384

/**
 * @brief Function that reads a line from a file with a limit of 16384 characters.
 * 
 * @param lineptr	Pointer to the line read to be filled.
 * @param n			Size of the line read.
 * @param fd		File descriptor of the file to read.
 * 
 * @return int		0 if the line is read, -1 if the end of the file is reached.
*/
int get_line_from_file(char **lineptr, int fd) {

	// Variables
	char get_line_buffer[GET_LINE_BUFFER_SIZE];
	memset(get_line_buffer, 0, GET_LINE_BUFFER_SIZE);
	int i = 0;
	char c;

	// Read the file character by character
	while (read(fd, &c, 1 * sizeof(char)) > 0) {

		// If the character is a \n, break the loop
		if (c == '\n') {

			// If i == 0 and the character is a \n, it means that the line is just a \n so we continue
			if (i == 0)
				continue;

			// Break
			break;
		}

		// Add the character to the buffer and continue
		get_line_buffer[i] = c;
		i++;
		if (i == (GET_LINE_BUFFER_SIZE - 1))
			break;
	}

	// If the buffer is empty, return -1 (end of file)
	if (i == 0)
		return -1;

	// Add the \0 at the end of the buffer
	get_line_buffer[i] = '\0';

	// If the lineptr is NULL, allocate it
	if (*lineptr == NULL) {
		ERROR_HANDLE_PTR_RETURN_INT((*lineptr = malloc(i + 1)), "get_line_from_file(): Unable to allocate the lineptr\n");
	}

	// If the lineptr is too small, reallocate it
	else {
		size_t lineptr_size = strlen(*lineptr);
		size_t possible_new_size = i + 1;
		if (lineptr_size < possible_new_size)
			ERROR_HANDLE_PTR_RETURN_INT((*lineptr = realloc(*lineptr, possible_new_size)), "get_line_from_file(): Unable to reallocate the lineptr\n");
	}

	// Copy the buffer to the lineptr
	memcpy(*lineptr, get_line_buffer, i + 1);

	// Return success
	return 0;
}

/**
 * @brief Function that checks if a file is accessible.
 * 
 * @param path	Path of the file to check.
 * 
 * @return int	0 if the file is accessible, -1 otherwise.
*/
int file_accessible(char* path) {
	
	// Open the file
	int fd = open(path, O_RDONLY);

	// If the file is not accessible, return -1
	if (fd == -1)
		return -1;
	
	// If the file is not readable, return -1
	byte c;
	int code = (read(fd, &c, 1) == 1) ? 0 : -1;

	// Close the file
	close(fd);

	// Return success
	return code;
}

/**
 * @brief Function that gets the size of a file.
 * 
 * @param fd	File descriptor of the file to get the size.
 * 
 * @return size_t	Size of the file.
*/
size_t get_file_size(int fd) {
	struct stat64 st;
	int code = fstat64(fd, &st);
	return (code == 0) ? st.st_size : 0;
}

/**
 * @brief Function that returns the hash value of a string.
 * 
 * @param str	String to hash.
 * 
 * @return int	Hash value of the string.
*/
int hash_string(char* str) {
	
	// Variables
	int hash = 0;
	int pow = 1;
	int i = 0;

	// Loop through the string
	while (str[i] != '\0') {

		// Add the character to the hash
		hash += str[i] * pow;

		// Increment the power
		pow *= 31;

		// Increment the index
		i++;
	}

	// Return the hash
	return hash;
}

