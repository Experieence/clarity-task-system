# ClariTask (C)
A simple command-line task manager built in C that models task load and mental clarity using a feedback loop system.

## Core Idea 
- The system is built by 3 core vaiables
- taskLoad: the number of active tasks
- definedActions: tasks with a defined next step that would aid in completion
- clarity: a calculated value representing mental clarity 

## Features 
- Add Task
- View Task
- Define next Action
- Complete Tasks
- Automatic Clarity calculation
- Maximum of 5 tasks

## Version History

### V1
Initial behavioural system implementation. 
Messy but functional prototype proving the model works.
### V2
Refractored modular version. 
Separated system logic, presentation and input handling. 
Improved readability and maintainability.
### Next Steps | V3
Will introduce structs to improve system state management. 
Also adding robustness and error handling making sure user inputs dont break the system.

