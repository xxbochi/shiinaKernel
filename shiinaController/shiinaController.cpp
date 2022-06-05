

#include <iostream>
#include "kernelinterface.hpp"
#include "offsets.hpp"

int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\shiina");

    ULONG address = Driver.GetClientAddress();
    ULONG processid = Driver.GetProcessId();

    std::cout << "ClientAddress: " << address << std::endl;   
    std::cout << "PID: " << processid << std::endl;

    while (true)
    {
        uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address + hazedumper::signatures::dwLocalPlayer, sizeof(uint32_t));

        Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, 0.f, sizeof(0.f));
    }
}

