/*
 * Gearsystem - Sega Master System / Game Gear Emulator
 * Copyright (C) 2013  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

#ifndef MEMORY_H
#define	MEMORY_H

#include "definitions.h"
#include "MemoryRule.h"
#include <vector>

class Memory
{
public:
    struct stDisassembleRecord
    {
        u16 address;
        char name[32];
        char bytes[16];
        int size;
        int bank;
    };

public:
    Memory();
    ~Memory();
    void Init();
    void Reset();
    void SetCurrentRule(MemoryRule* pRule);
    MemoryRule* GetCurrentRule();
    u8* GetMemoryMap();
    u8 Read(u16 address, u16 pc);
    void Write(u16 address, u8 value, u16 pc);
    u8 Retrieve(u16 address);
    void Load(u16 address, u8 value);
    stDisassembleRecord** GetDisassembledMemoryMap();
    stDisassembleRecord** GetDisassembledROMMemoryMap();
    void LoadSlotsFromROM(u8* pTheROM, int size);
    void MemoryDump(const char* szFilePath);
    void SaveState(std::ostream& stream);
    void LoadState(std::istream& stream);
    std::vector<stDisassembleRecord*>* GetBreakpoints();
    stDisassembleRecord* GetRunToBreakpoint();
    void SetRunToBreakpoint(stDisassembleRecord* pBreakpoint);

private:
    MemoryRule* m_pCurrentMemoryRule;
    u8* m_pMap;
    stDisassembleRecord** m_pDisassembledMap;
    stDisassembleRecord** m_pDisassembledROMMap;
    std::vector<stDisassembleRecord*> m_Breakpoints;
    stDisassembleRecord* m_pRunToBreakpoint;
};

#include "Memory_inline.h"

#endif	/* MEMORY_H */
