//#include <curses.h>
#include <string>
#include <vector>
#include <iostream>
#include <ctime> 

struct ProcessInfo {
    int pid;
    std::string type;
    std::string name;
    std::string memory;
};



//void gpuSummary() {
//    printw("+-----------------------------------------------------------------------------------------+\n");
//    printw("| NVIDIA-SMI 572.40                 Driver Version: 572.40         CUDA Version: 12.8     |\n");
//    printw("|-----------------------------------------+------------------------+----------------------+\n");
//    printw("| GPU  Name                  Driver-Model | Bus-Id          Disp.A | Volatile Uncorr. ECC |\n");
//    printw("| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |\n");
//    printw("|===============================+======================+==================================|\n");
//    printw("|   0  NVIDIA GeForce MX450         WDDM  |   00000000:05:00.0 Off |                  N/A |\n");
//    printw("| N/A   56C    P8            N/A  / 5001W |       1MiB /   2048MiB |      0%%      Default |\n");
//    printw("|                                         |                        |                  N/A |\n");
//    printw("+-----------------------------------------------------------------------------------------+\n\n");
//}

void gpuSummary() {
    std::cout << "+-----------------------------------------------------------------------------------------+\n"
                 "| NVIDIA-SMI 572.40                 Driver Version: 572.40         CUDA Version: 12.8     |\n"
                 "|-----------------------------------------+------------------------+----------------------+\n"
                 "| GPU  Name                  Driver-Model | Bus-Id          Disp.A | Volatile Uncorr. ECC |\n"
                 "| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |\n"
                 "|===============================+======================+==================================|\n"
                 "|   0  NVIDIA GeForce MX450         WDDM  |   00000000:05:00.0 Off |                  N/A |\n"
                 "| N/A   56C    P8            N/A  / 5001W |       1MiB /   2048MiB |      0%%      Default|\n"
                 "|                                         |                        |                  N/A |\n"
                 "+-----------------------------------------------------------------------------------------+\n\n";
}

std::string trimName(const std::string& pName, size_t width) {
    if (pName.size() <= width) {
        return pName;
    }
    else {
        return  "..." + pName.substr(pName.size() - (width - 3));
    }
}

//void processSummary(const std::vector<ProcessInfo> process) {
//    printw("+-----------------------------------------------------------------------------------------+\n");
//    printw("| Processes:                                                                              |\n");
//    printw("|  GPU   GI   CI              PID   Type   Process name                        GPU Memory |\n");
//    printw("|        ID   ID                                                               Usage      |\n");
//    printw("|=========================================================================================|\n");
//
//    // Print dummy processes
//    for (ProcessInfo p : process) {
//        std::string new_name = trimName(p.name, 32);
//        printw("|    0   N/A  N/A           %5d   %4s   %20s %9s     |\n",
//            p.pid, p.type.c_str(), new_name.c_str(), p.memory.c_str());
//    }
//    printw("+-----------------------------------------------------------------------------------------+\n");
//
//}

void processSummary(const std::vector<ProcessInfo> process) {
        std::cout << "+-----------------------------------------------------------------------------------------+\n"
                     "| Processes:                                                                              |\n"
                     "|  GPU   GI   CI              PID   Type   Process name                        GPU Memory |\n"
                     "|        ID   ID                                                               Usage      |\n"
                     "|=========================================================================================|\n";
    
        // Print dummy processes
        for (ProcessInfo p : process) {
            std::string new_name = trimName(p.name, 32);
            std::printf("|    0   N/A  N/A           %5d   %4s   %20s %9s     |\n",
                p.pid, p.type.c_str(), new_name.c_str(), p.memory.c_str());
        }
        std::cout << "+-----------------------------------------------------------------------------------------+\n";
    
 }

int main() {
    //initscr();

    char timestamp[30];
    time_t dt = time(0);
    ctime_s(timestamp, sizeof(timestamp), &dt);
    std::cout << timestamp;

    // Draw GPU Summary
    gpuSummary();

    // Dummy process list
    std::vector<ProcessInfo> processes = { 
        {20348, "C+G", "C:\\Program Files (x86)\\Overwolf\\Overwolf.exe", "N/A"},
        {46218, "C+G", "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", "N/A"},
        {95472, "C+G", "C:\\Riot Games\\VALORANT\\live\\VALORANT.exe", "N/A"},
        {89631, "C+G", "C:\\Program Files\\FireAlpaca\\FireAlpaca64\\FireAlpaca20\\FireAlpaca.exe", "N/A"},
        {53867, "C+G", "C:\\Program Files (x86)\\Steam\\GameOverlayUI.exe", "N/A"},
    };

    // Print process summary
    processSummary(processes);
    
    //printw("Press any key to exit...");
    //refresh();

    //getch(); // Wait for user input

    //endwin(); // End curses mode
    return 0;
}
