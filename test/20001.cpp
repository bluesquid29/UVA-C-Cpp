#include <iostream>
#include <thread>   // std::this_thread
#include <chrono>   // std::chrono

int main() 
{
	using std::cout;	    
    
    cout << "=== 測試 1: 進度條 (flush) ===\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "processing: ";
    for (int i = 0; i < 10; i++) 
    {
        cout << "█" << std::flush;  // 每次立即顯示
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    cout << " 100%" << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << " 完成!\n";
    
    
    
    cout << "=== 測試 2: 進度條 (no flush) ===\n";
    cout << "processing: ";
    for (int i = 0; i < 10; i++) 
    {
        cout << "█";                // 全部跑玩後才顯示
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    cout << " 100%";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << " 完成!\n";
    
    return 0;
}