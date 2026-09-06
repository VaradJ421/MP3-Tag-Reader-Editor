# MP3-Tag-Reader-Editor
Built a tool to read and modify MP3 metadata (ID3 tags) like Title, Artist, and Album without affecting audio quality. 🔧 Learned: Binary file handling, ID3 parsing, memory management 💡 Focus: Data integrity &amp; efficient file processing This project strengthened my understanding of low-level programming and real-world file formats.
# 🎵 MP3 Tag Reader & Editor

A **C-based MP3 Tag Reader & Editor** developed to read and modify **MP3 metadata (ID3 tags)** such as Title, Artist, Album, and other information without affecting the actual audio content.

This project was developed as part of my **Embedded Systems training at Emertxe Information Technologies** and focuses on **binary file handling, ID3 tag parsing, memory management, and efficient file processing**.

## 📌 Project Overview

MP3 files can contain metadata known as **ID3 tags**, which store information about the audio file.

This application provides a simple command-line interface to:

* 📖 Read MP3 metadata
* ✏️ Edit MP3 metadata
* 💾 Save modified metadata
* 🎵 Preserve the actual audio data
* 🔍 Parse binary MP3 file structures
* ⚡ Process files efficiently

The project helped strengthen my understanding of **low-level programming and real-world binary file formats**.

## ✨ Features

* 📖 **Read MP3 Tags** – Display metadata stored in an MP3 file.
* ✏️ **Edit MP3 Tags** – Modify supported metadata fields.
* 🎵 **Title Editing** – Update the song title.
* 👤 **Artist Editing** – Update artist information.
* 💿 **Album Editing** – Update album information.
* 📅 **Year Editing** – Modify year information where supported.
* 🎼 **Genre Editing** – Update genre metadata where supported.
* 💾 **File Preservation** – Maintain the original audio data while modifying metadata.
* ⚠️ **Input Validation** – Validate user input and file operations.

## 🧠 What are ID3 Tags?

**ID3** is a metadata container used in MP3 files to store information about an audio track.

Common metadata fields include:

| Tag     | Description            |
| ------- | ---------------------- |
| Title   | Name of the song       |
| Artist  | Artist or performer    |
| Album   | Album name             |
| Year    | Release year           |
| Genre   | Music genre            |
| Comment | Additional information |

Example:

```text
MP3 File
│
├── ID3 Metadata
│   ├── Title
│   ├── Artist
│   ├── Album
│   ├── Year
│   └── Genre
│
└── Audio Data
```

The application works with the metadata portion while preserving the underlying audio content.

## 🏗️ Application Architecture

```text
                 MP3 File
                    │
                    ▼
             ┌──────────────┐
             │ File Reader  │
             └──────┬───────┘
                    │
                    ▼
             ┌──────────────┐
             │ ID3 Parser   │
             └──────┬───────┘
                    │
          ┌─────────┴─────────┐
          ▼                   ▼
    Read Metadata        Edit Metadata
          │                   │
          └─────────┬─────────┘
                    ▼
             ┌──────────────┐
             │ File Writer  │
             └──────┬───────┘
                    │
                    ▼
             Updated MP3 File
```

## 🛠️ Technologies Used

| Category             | Technology                              |
| -------------------- | --------------------------------------- |
| Programming Language | C                                       |
| Interface            | Command Line                            |
| File Type            | MP3                                     |
| Metadata             | ID3 Tags                                |
| File Handling        | Binary File I/O                         |
| Platform             | Linux / GCC                             |
| Core Concepts        | Structures, Pointers, Memory Management |

## 🔧 Key Concepts Demonstrated

### 1. Binary File Handling

The project works directly with MP3 files in **binary mode**, allowing metadata to be read and modified at the byte level.

Important C file operations include:

```c
fopen()
fread()
fwrite()
fseek()
ftell()
fclose()
```

### 2. ID3 Tag Parsing

The application identifies and processes metadata fields stored in the MP3 file.

```text
MP3 File
   │
   ▼
Read Header
   │
   ▼
Identify ID3 Tags
   │
   ▼
Read Frame Information
   │
   ▼
Extract Metadata
```

### 3. Memory Management

Dynamic memory and buffers are used where required to process metadata efficiently.

Concepts include:

* Pointers
* Dynamic memory allocation
* Buffer management
* Memory deallocation

### 4. Data Integrity

The application is designed to modify metadata while preserving the actual audio content.

```text
Before Editing
──────────────────────
MP3 Metadata + Audio
        │
        ▼
   Tag Modification
        │
        ▼
After Editing
──────────────────────
Updated Metadata + Same Audio
```

## 📁 Project Structure

```text
MP3-Tag-Reader-Editor/
│
├── main.c
├── mp3_tag_reader.c
├── mp3_tag_reader.h
├── mp3_tag_editor.c
├── mp3_tag_editor.h
├── types.h
├── common.h
├── Makefile
└── README.md
```

> Update the file structure according to the actual files present in your repository.

## ⚙️ Installation & Setup

### Clone the Repository

```bash
git clone https://github.com/VaradJ421/MP3-Tag-Reader-Editor.git
```

### Navigate to the Project

```bash
cd MP3-Tag-Reader-Editor
```

### Compile

If your project contains a Makefile:

```bash
make
```

Alternatively, using GCC:

```bash
gcc *.c -o mp3tag
```

## ▶️ Usage

### Read MP3 Metadata

The general command may look like:

```bash
./mp3tag -v song.mp3
```

Example:

```text
MP3 Tag Reader
-------------------------
Title  : Example Song
Artist : Example Artist
Album  : Example Album
Year   : 2025
Genre  : Pop
```

### Edit MP3 Metadata

The general format may look like:

```bash
./mp3tag -e song.mp3
```

The application can then prompt the user to select the metadata field to modify.

Example:

```text
MP3 Tag Editor
-------------------------

1. Edit Title
2. Edit Artist
3. Edit Album
4. Edit Year
5. Edit Genre
6. Exit

Enter your choice:
```

> Adjust the commands above according to the exact command-line interface implemented in your project.

## 🔄 Example Workflow

```text
             song.mp3
                 │
                 ▼
        ┌─────────────────┐
        │  Read ID3 Tags  │
        └────────┬────────┘
                 │
                 ▼
          Display Metadata
                 │
                 ▼
          Select Tag to Edit
                 │
                 ▼
          Update Metadata
                 │
                 ▼
        Save Updated MP3 File
                 │
                 ▼
             song.mp3
```

## 🎯 Project Objectives

The main objectives of this project were to:

* Understand binary file formats.
* Learn how metadata is stored inside MP3 files.
* Implement ID3 tag parsing.
* Work with low-level file operations.
* Practice pointers and memory management.
* Maintain data integrity during file modification.
* Develop a practical command-line utility in C.

## ⚠️ Limitations

* Supports only the ID3 tags implemented in the project.
* Metadata compatibility may depend on the MP3 file's ID3 version.
* The application is primarily designed for learning and demonstration.
* Some MP3 files may contain metadata formats or structures not supported by the implementation.

## 🚀 Future Enhancements

Possible improvements include:

* [ ] Support additional ID3 versions
* [ ] Support more ID3 frames
* [ ] Add album-art support
* [ ] Add batch MP3 metadata editing
* [ ] Add advanced metadata validation
* [ ] Improve error handling
* [ ] Add automated test cases
* [ ] Add a graphical user interface
* [ ] Add support for additional audio metadata formats

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

* C programming
* Binary file processing
* File I/O operations
* ID3 metadata parsing
* Structures and pointers
* Memory management
* Data validation
* Low-level programming
* Real-world file-format handling
* Data integrity and efficient file processing

## 💡 Key Takeaway

This project strengthened my understanding of how **real-world binary file formats are structured and processed at a low level**.

Working with MP3 metadata provided practical experience in combining **C programming, binary file handling, memory management, and data integrity** to build a useful command-line application.

## 👨‍💻 Author

**Varad Umesh Jinturkar**

Embedded Systems | C Programming | Data & AI Enthusiast

GitHub: **[@VaradJ421](https://github.com/VaradJ421)**

## ⭐ Support

If you find this project useful for learning **C programming, binary file handling, ID3 metadata, or low-level programming**, consider giving the repository a ⭐.

