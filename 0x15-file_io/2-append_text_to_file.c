#include "main.h"

/**
 * append_text_to_file - Add text at the end of a file.
 * @filename:  Is the name of the file.
 * @text_content: is the NULL terminated string to add at the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int open_file, write1, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	open_file = open(filename, O_WRONLY | O_APPEND);
	write1 = write(open_file, text_content, length);

	if (open_file == -1 || write1 == -1)
		return (-1);

	close(open_file);

	return (1);
}
