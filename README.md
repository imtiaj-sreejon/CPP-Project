# CPP-Project
Project Name: IUT Cafeteria Management System

Language used: C++, SQL

Short Description:
The project aims at automating the usual management system of IUT Cafeteria. Features of this project include:

    i) Non-residential students can book their next meals beforehand through their smart card
    ii) Admins will be able to add students to the database for ensuring security
    iii) Students will be able to comment about their meal
    iv) Admins will scrutinize the complains and take steps accordingly
    v) Food menu can be viewed
    vi) Suggestions about the improvement of cafeteria as well as inclusion of any new feature to this project can be provided
    vii) The project has been made robust through the use of databse management system underlying the API which was quite difficult with the traditional file system approach

Steps to run this program in local machine:

    1. At first clone the project from the project home
    
    2. Next download SQLapi library from http://www.sqlapi.com/Download/sqlapi_trial.exe(for windows)
    
    3. Next navigate to the corresponding visual studio or gcc folder and copy-paste all the .dll files inside bin folder to C:\Windows\System32 and the project folder where the source files are present
    For example, in our case, the compiler was Microsoft Visual Studio 2017 and the machine was 64-bit. So the bin folder was SQLAPI\vs2017\x86_64\bin
    
    4.Inside project properties change the project platform to x64 from configuration manager if your machine is 64-bit. Otherwise no need to change anything
    
    5.Next navigate to C/C++ in project properties.Now in the "additional include directories" row add two file paths:
    one is path to include folder inside the installed sqlapi folder located in SQLAPI\include and another is corresponding database folder which is installed on the local machine
    for example, for windows machine and oracle database the folder will be ora_win and required file path will be SQLAPI\include\ora_win
    
    6. Navigate to Linker. Now in the "additional library directories" row add a file path corresponding to lib folder which was with the bin folder in the 2nd step. For example, for previous case, path would be SQLAPI\vs2017\x86_64\lib
    
    7. Now the setup part is complete. Then compile the project and run and you are good to go.
    
 If anyone faces any problem or has any query then s/he is requested to give the detailes of his/her problem in the issue section of the project.
