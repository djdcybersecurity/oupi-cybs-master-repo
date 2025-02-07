[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18030304)
# CPU Virtualization Assignment

## **Overview**
In this assignment, you will explore how operating systems manage multiple processes on systems with limited CPU resources. Your goal is to observe how three separate processes run "simultaneously" on a system with only two CPUs by leveraging process scheduling.

---

## **Steps**

### **1. Compile the Program**
You are provided with a program that simulates a task running continuously. First, compile the program using the following command:

```bash
gcc -o cpu cpu.c
```

---

### **2. Run Three Processes Simultaneously**
You will execute three instances of the program at the same time, each with a different input string. Use the `&` operator to run these processes in the background:

```bash
./cpu "Task A" & ./cpu "Task B" & ./cpu "Task C" &
```

This will create three running tasks, even though your Codespaces instance has only **two CPUs**.

---

### **3. Observe the Processes**
1. Open another terminal and run:
   ```bash
   htop
   ```
   - In `htop`, observe the CPU utilization and note that only **two processes** are actively running at any given time.
   - The third process will be waiting for its turn, as the system only has two CPUs.

2. Pay attention to the **PIDs (Process IDs)** and the CPU utilization for each process. Observing the PIDs allows you to identify which processes are running or waiting. This demonstrates the CPU scheduling concept, where the operating system dynamically allocates CPU time to active processes to create the illusion of simultaneous execution.

---

### **4. Modify the Program**
To better visualize how the OS schedules processes, modify the program to include:
1. **Process ID (PID):** Display the PID of each process in its output.
2. **Formatted Output:** Add a `printf` statement to display all the following information in a single line:
   - The process's custom string (e.g., "Task A").
   - The PID of the process.
   - The CPU the process is running on.

Modify the `Spin()` function to look like this:

```c
void Spin(int seconds) {
    sleep(seconds);
}
```

Update the main loop to include the formatted output:

```c
while (1) {
    Spin(1);
    printf("%s, [PID %d] Running on CPU %d\n", str, getpid(), sched_getcpu());
    fflush(stdout);
}
```

---

### **5. Run the Modified Program**
Recompile the program with the modified code:
```bash
gcc -o cpu cpu.c
```

Run the three processes again:
```bash
./cpu "Task A" & ./cpu "Task B" & ./cpu "Task C" &
```

Observe the output in your terminal and in `htop`. You should now see:
- Each process identifying itself by PID.
- The input string you provided (e.g., "Task A").
- The CPU core each process is using.

---

## **What to Submit**
1. **Modified Code:** Submit your updated `cpu.c` file.
2. **Screenshots:**
   - A terminal screenshot showing the program's output with formatted information, including the process name, PID, and CPU core.
   - A screenshot of `htop` showing three processes running and their PIDs.

---

## **Key Question**
1. **Why do the three processes appear to run simultaneously, even though there are only two CPUs?**

---
