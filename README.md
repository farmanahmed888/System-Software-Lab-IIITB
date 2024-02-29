# System-Software-Lab-IIITB
# Academia Portal

The Academia Portal is a multifunctional system that manages student and faculty details, course information, and user accounts within an educational institution. This project utilizes socket programming to allow multiple clients to connect to a central server, enabling access to specific academic details based on user roles.

## Features

- **User Management**: The system supports three roles: Faculty, Student, and Administrator. Each role has specific functionalities and access levels.
- **Login System**: All users must enter their accounts through a login system. Administrative access is password-protected to prevent unauthorized access.
- **Functionality by Role**:
  - *Administrator*: Can add and manage student and faculty details, courses, and user accounts.
  - *Faculty*: Can add new courses, manage course enrollments, and change passwords.
  - *Student*: Can enrol in or unenroll from courses, view enrolled courses, and change passwords.
- **File-based Storage**: Student and faculty details, as well as course information, are stored in files for easy management and access.
- **Concurrency Control**: Read and write locks are implemented to protect critical data sections. Read locks are used to view course details, while write locks are used for enrollment and unenrollment operations.
- **System Calls Usage**: The project employs system calls instead of library functions wherever possible, including process management, file management, file locking, semaphores, multithreading, and inter-process communication mechanisms.
- **Socket Programming**: The server maintains the database and serves multiple clients concurrently. Clients can connect to the server and access their specific academic details.

## Installation

1. Clone the repository to your local machine.
2. Ensure you have GCC installed.
3. Navigate to the project directory.
4. Run the server script to start the server, and provide the port number for both the server port and the client port.
5. Run the client script to connect to the server using the port number and access the Academia Portal.

## Usage

1. **Administrator**:
   - Connect to the server.
   - Enter login credentials.
   - Access administrative functionalities such as adding students/faculty, managing courses, and user accounts.

2. **Faculty**:
   - Connect to the server.
   - Enter login credentials.
   - Access functionalities like adding courses, managing enrollments, and changing passwords.

3. **Student**:
   - Connect to the server.
   - Enter login credentials.
   - Access options to enrol/unenroll from courses, view enrolled courses, and change passwords.

