Демонстрация использования библиотеки fast compiling (fc) в части упакови и распаковки данных.
 1. Создать проект в clion
 2. git init
 3. git add main.cpp CMakeLists.txt
 4. git commit
 5. git submodule add https://github.com/steemit/fc.git
 6. git submodule update --init --recursive
 7. git commit -m "Added FC submodule"
 8. add_subdirectory( fc )
 9. target_link_libraries (project_name fc)
 
 
 https://stackoverflow.com/questions/1811730/how-do-i-work-with-a-git-repository-within-another-repository