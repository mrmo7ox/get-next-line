<div align="center">
  <img style="text-align: center;" width="200" src="https://mo7ox.com/wp-content/uploads/2025/04/getnextline.png">
</div>

# 📜 get-next-line

Welcome to the **get-next-line** project! This repository is part of the 42 curriculum, and it implements a function that reads and returns a single line from a file descriptor. 🚀

---

## 🌟 Features

- Reads a single line from a file at a time.
- Handles multiple file descriptors simultaneously.
- Efficient and memory-friendly.

---

## 🛠️ How It Works

The `get_next_line` function operates as follows:

1. **File Descriptor Input:** The function takes a file descriptor as input.
2. **Read in Chunks:** It reads the file content in chunks of a specified buffer size.
3. **Store and Process:** Uses a static variable to store the remaining content between calls and processes it to extract a single line.
4. **Line-by-Line:** Returns one line at a time until the end of the file is reached.

This approach ensures that the function works efficiently for files of varying sizes while keeping memory usage under control.

---

## 💻 Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/mrmo7ox/get-next-line.git
   cd get-next-line
   ```

2. Include `get_next_line.c` and `get_next_line.h` in your project.

3. Compile your project with the required flags.

4. Call `get_next_line()` in your program, passing a valid file descriptor.

Example:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 📂 Repository Structure

```plaintext
.
├── get_next_line.c    # Core function implementation
├── get_next_line.h    # Header file
├── main.c             # Example usage (optional)
└── README.md          # This file
```

---

## 🛡️ License

This project is part of the 42 curriculum and adheres to its norms and guidelines.

---

### 🤝 Contributing

Contributions are welcome! Feel free to fork this repository, make improvements, and submit a pull request. 

---

Happy coding! 🎉
