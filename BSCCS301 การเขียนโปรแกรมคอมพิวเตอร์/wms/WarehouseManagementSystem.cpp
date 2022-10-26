// ********************************************************************************************
//  ________  ________           ________  _____ ______   _________  ___  ___  ___
// |\   ____\|\   ____\         |\   __  \|\   _ \  _   \|\___   ___|\  \|\  \|\  \         
// \ \  \___|\ \  \___|_        \ \  \|\  \ \  \\\__\ \  \|___ \  \_\ \  \\\  \ \  \        
//  \ \  \    \ \_____  \        \ \   _  _\ \  \\|__| \  \   \ \  \ \ \  \\\  \ \  \       
//   \ \  \____\|____|\  \        \ \  \\  \\ \  \    \ \  \   \ \  \ \ \  \\\  \ \  \____
//    \ \_______\____\_\  \        \ \__\\ _\\ \__\    \ \__\   \ \__\ \ \_______\ \_______\
//     \|_______|\_________\        \|__|\|__|\|__|     \|__|    \|__|  \|_______|\|_______|
//              \|_________|
// code by Mr.Jeerasak Ananta
// Mini Project Computer Science RMUTL NAN
// ********************************************************************************************

#include <iostream>
#include <stdio.h>  // IO ของ ภาษา C ปริติก
#include <stdlib.h> // เรียกใช้งาน  ล้างหข้าจอ
#include <fstream>  //  เรียกใช้งาน การเปฺิดเเละการ ปิดของไฟล์
#include <string>   // สตริง
#include <vector>   // array ขนาดเป็นการปรับได้
#include <sstream>  // ตัว string วัตุว การเปลี่ยนจาก ตัวเลชให้เป็น string
#include <iomanip>  // จัดขนากของช่องไฟ

using namespace std;

// ประกาศตัวเเปลเพิ่อเรียกใช้ภายหลัง
int recordNumber = 0;
string modeprogram = "NO Mode!";
string modeprogramUnit = "NO Mode!";

// ประการ ชื่อที่เก็บไฟล์เป็นค่าของตัวเเปรเพื่อที่ จะได้ เก็บเขามาใช้ได้
string filename = "database.csv";

// gobal data Array เพื่อทำการเก็บค่าของ ข้อมูลที่อ่านเข้ามา และไว้ใช้ภายหลังโดยที่มีขนาดเป็น 2D
// ขนาดเป็น [100][100]
string data[100][100];

// function write  data in array to file
// ฟังก์ชั้นเขียนไฟล์ ที่อยู่ใน array Data
void write_file()
{
    // เปิดไฟล์
    fstream file(filename.c_str());
    // loop ไปไปยังขนาดของ  recordNumber ที่เก็บค่า บันทัดของ array date[100][100]
    for (int i = 0; i < recordNumber; i++)
    {
        // ยึนทึกออกไฟล์ ตามIndex ของ array
        file << data[i][0] << "," << data[i][1] << "," << data[i][2] << "," << data[i][3] << "," << data[i][4] << "," << data[i][5] << "," << data[i][6] << "," << data[i][7] << "," << data[i][8] << "," << data[i][9] << "," << data[i][10] << "," << data[i][11] << "," << data[i][12] << endl;
    }
    // ปิดไฟล์
    file.close();
}

//  Warehouse Management System
// Report()
// ฟังก์ขันนี้ทำงาน เเสดงค่าของ ข้อมูลที่อยู่ภายใน array data
void Report()
{

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "======================    Report  MENU    ==========================================================================================================" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Id" << setw(10) << "| CodeID" << setw(10) << "| Name" << setw(10) << "| Price" << setw(10) << "| Date" << setw(15) << "| Amount" << setw(15) << "| Receiving" << setw(15) << "| Confirmation" << setw(10) << "| Route" << setw(10) << "| Receipt" << setw(10) << "| Payment" << setw(9) << "| Source" << setw(15) << "| Destination" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    // loop in array
    for (int i = 1; i < recordNumber; i++)
    {
        cout << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][3] << setw(15) << data[i][4] << setw(10) << data[i][5] << setw(15) << data[i][6] << setw(15) << data[i][7] << setw(10) << data[i][8] << setw(10) << data[i][9] << setw(10) << data[i][10] << setw(15) << data[i][11] << setw(15) << data[i][12] << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "All Recrd -> " << recordNumber - 1 << endl;
    cout << "Mode Program -> " << modeprogram << endl;
    cout << "Mode count Unit -> " << modeprogramUnit << endl;
}

//  ฟังก์ชั้นนี้ทำหน้าที่ เพิ่มเข้า aray เล้ว บันทึก ไฟล์
void StockEntry()
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "======================    StockEntry MENU   ==========================" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // add reacord += 1
    // ให้ user input เเล้วเก็บค่าตาม Index ของ array date[recordNumber][index]
    cout << "Enter product CodeID: ";
    cin >> data[recordNumber][1];
    cout << "Enter product name: ";
    cin >> data[recordNumber][2];
    cout << "Enter product prict:";
    cin >> data[recordNumber][3];
    cout << "Enter product date: ";
    cin >> data[recordNumber][4];
    cout << "Enter amount: ";
    cin >> data[recordNumber][5];

    // เพิ่มค่าพื้นฐานในกับ user ที่ไม่ได้ ใส่ค่าลงมา
    //  เปลี่ยนค่าจาก int ให้เป็น
    stringstream inint;
    inint << recordNumber;
    string strin;
    inint >> strin;
    // เพิ่มค่าให้
    data[recordNumber][0] = strin;
    data[recordNumber][6] = "NO";
    data[recordNumber][7] = "NO";
    data[recordNumber][8] = "CompanyTruck";
    data[recordNumber][9] = "NUll";
    data[recordNumber][10] = "empty";
    data[recordNumber][11] = "Nan";
    data[recordNumber][12] = "Empty";

    // เพิ่มค่าของ recordNumber ไปหนึ่งค่า
    recordNumber++;
    // เรียกฟังก์ชั้นการอ่าน ไฟล์
    write_file();
}
void Documenting()
{
    /* ระบบจัดการเอกสารต่างๆ เป็นอีกองค์ประกอบสำคัญ
    ที่จะคอยสรุปข้อมูลการทำธุรกรรมต่างๆ (Transaction) ภายในคลังสินค้า
    ใบส่งของ (Delivery Note)
    ใบเสร็จการสั่งซื้อ (Purchase Receipt)
    ใบเบิกพัสดุหรือวัตถุดิบ (Material Request)
    รายการสิ่งของตามใบสั่ง/ใบเบิก (Pick List)
 */
    bool chakeing = 0;
    while (chakeing == 0)
    {
        cout << "----------------------------------------------------------------------" << endl;
        cout << "======================    Documenting  MENU     ======================" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "*                   (1) Delivery Note                                *" << endl;
        cout << "*                   (2) Purchase Receipt                             *" << endl;
        cout << "*                   (3) Material Request                             *" << endl;
        cout << "*                   (4) Pick List                                    *" << endl;
        cout << "*                   (0) END Documenting  MENU                        *" << endl;
        cout << "----------------------------------------------------------------------\n";

        char input;
        cout << "Ente number : ";
        cin >> input;
        switch (input)
        {
        case '0':
        {
            /* code */
            chakeing = 1;
        }
        break;
        case '1':
        {
            bool checkCase = 0;
            while (checkCase == 0)
            {
                /* code */

                char in;
                cout << "Do you want to print Delivery Note? " << endl;
                cout << "Yse (1):" << endl;
                cout << "NO (0):" << endl;
                cout << ">> ";
                cin >> in;
                switch (in)
                {
                case '0':
                    /* code */
                    checkCase = 1;

                    break;
                case '1':
                    cout << "----------------------------------------------------------------------\n";
                    cout << "Print  Delivery Note " << endl;
                    cout << "DONE!" << endl;
                    checkCase = 1;
                    cout << "======================================================================\n";
                    break;

                default:
                    cout << "----------------------------------------------------------------------\n";

                    cout << "You in put wront!! " << endl;
                    cout << "Enter Number 1 or 0 again" << endl;
                    cout << "----------------------------------------------------------------------\n";

                    break;
                }
            }
        }
        break;
        case '2':
        {
            bool checkCase = 0;
            while (checkCase == 0)
            {
                /* code */

                char in;
                cout << "Do you want to print Purchase Receipt? " << endl;
                cout << "Yse (1):" << endl;
                cout << "NO (0):" << endl;
                cout << ">> ";
                cin >> in;
                switch (in)
                {
                case '0':
                    /* code */
                    checkCase = 1;

                    break;
                case '1':
                    cout << "----------------------------------------------------------------------\n";
                    cout << "Purchase Receipt" << endl;
                    cout << "DONE!" << endl;
                    checkCase = 1;
                    cout << "======================================================================\n";
                    break;

                default:
                    cout << "----------------------------------------------------------------------\n";

                    cout << "You in put wront!! " << endl;
                    cout << "Enter Number 1 or 0 again" << endl;
                    cout << "----------------------------------------------------------------------\n";

                    break;
                }
            }
        }
        break;
        case '3':
        {
            bool checkCase = 0;
            while (checkCase == 0)
            {
                /* code */

                char in;
                cout << "Do you want to print Material Request? " << endl;
                cout << "Yse (1):" << endl;
                cout << "NO (0):" << endl;
                cout << ">> ";
                cin >> in;
                switch (in)
                {
                case '0':
                    /* code */
                    checkCase = 1;

                    break;
                case '1':
                    cout << "----------------------------------------------------------------------\n";
                    cout << "Material Request" << endl;
                    cout << "DONE!" << endl;
                    checkCase = 1;
                    cout << "======================================================================\n";
                    break;

                default:
                    cout << "----------------------------------------------------------------------\n";

                    cout << "You in put wront!! " << endl;
                    cout << "Enter Number 1 or 0 again" << endl;
                    cout << "----------------------------------------------------------------------\n";

                    break;
                }
            }
        }
        break;
        case '4':
        {
            bool checkCase = 0;
            while (checkCase == 0)
            {
                /* code */

                char in;
                cout << "Do you want to Print Pick List? " << endl;
                cout << "Yse (1):" << endl;
                cout << "NO (0):" << endl;
                cin >> in;
                switch (in)
                {
                case '0':
                    /* code */
                    checkCase = 1;

                    break;
                case '1':
                    cout << "----------------------------------------------------------------------\n";

                    cout << "Pick List " << endl;
                    cout << "DONE!" << endl;
                    checkCase = 1;
                    cout << "======================================================================\n";

                    break;

                default:
                    cout << "----------------------------------------------------------------------\n";

                    cout << "You in put wront!! " << endl;
                    cout << "Enter Numbere again" << endl;
                    cout << "----------------------------------------------------------------------\n";

                    break;
                }
            }
        }
        break;

        default:
            cout << "----------------------------------------------------------------------\n";

            cout << "You in put wront!! " << endl;
            cout << "Enter Numbere again" << endl;
            cout << "----------------------------------------------------------------------\n";

            break;
        }
    }
}
//  ฟังก์ขั้นทำหน้าที่่เป็น mode ของ การเก็บ จะเอาเป็นเเบบใหน
//  Single Product สิ้นค่าเดียว
//  Bundle Product สิ่งค่าที่เป็น คู่
void InventoryManagement()
{
    //
    bool checking = 0;
    while (checking == 0)
    {

        cout << "----------------------------------------------------------------------" << endl;
        cout << "=============      Inventory Management  MENU  =======================" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "*                   (1) Single Product                               *" << endl;
        cout << "*                   (2) Bundle Product                               *" << endl;
        cout << "*                   (0) END Documenting  MENU                        *" << endl;
        cout << "----------------------------------------------------------------------\n";
        // ให้
        char input;
        cout << "You want to change the mode of collecting?" << endl;
        cout << "Enter number : ";
        cin >> input;
        switch (input)
        {
        case '0':
        {
            checking = 1;
        }
        break;
        case '1':
        {
            cout << "Change Mode to Single Product." << endl;
            cout << "DONE" << endl;
            cout << "======================================================================\n";
            modeprogram = "Single Product";
            checking = 1;
        }

        break;
        case '2':
        {
            cout << "Change Mode to Bundle Product." << endl;
            cout << "DONE" << endl;
            cout << "======================================================================\n";
            modeprogram = "Bundle Product";
            checking = 1;
        }

        default:
            cout << "----------------------------------------------------------------------\n";
            cout << "-------------------X X X X X X X X -----------------------------------\n";
            cout << "You in put wront!! " << endl;
            cout << "Enter Numbere again" << endl;
            cout << "----------------------------------------------------------------------\n";
            break;
        }
    }
}

// Transportation Management System (TMS)
/* (1) Receiving transport orders   การรับคำสั่งการขนส่ง และ การตรวจสอบสถานะการขนส่ง
   (2) confirmation of acceptance   การยืนยันการรับงาน
   (3) Route and trip management    การจัดการเส้นทางและเที่ยวรถ
   (4) Receipt confirmation system  ระบบยืนยันการรับของ
   (5) payment collection           การเก็บชำระเงินและบันทึกรายรับรายจ่าย

 */
// ฟังก์ชั้นนี้ทำหน้าที่เปลี่ยนค่าของ ตามที่ user ต้องการ
void InventoryTransfers()
{
    bool checking = 0;
    while (checking == 0)
    {

        cout << "----------------------------------------------------------------------" << endl;
        cout << "===============    Inventory Transfers  MENU    ======================" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "*                   (1) Receiving transport orders                   *" << endl;
        cout << "*                   (2) Confirmation of acceptance                   *" << endl;
        cout << "*                   (3) Route and trip management                    *" << endl;
        cout << "*                   (4) Receipt confirmation system                  *" << endl;
        cout << "*                   (5) Payment collection                           *" << endl;
        cout << "*                   (6) Source                                       *" << endl;
        cout << "*                   (7) Destination                                  *" << endl;
        cout << "*                   (8) Display Reptor                               *" << endl;
        cout << "*                   (0) END Documenting  MENU                        *" << endl;
        cout << "----------------------------------------------------------------------\n";
        cout << "Ente  number :";
        char input;
        cin >> input;
        switch (input)
        {
        case '0':
            checking = 1;

            break;
        case '1':
        {

            // display  รายการ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                   Receiving transport orders                       *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Status" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][6] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit Receiving transport Status!" << endl;
                cout << "Yse (1) or No (0)" << endl;
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {
                        /* code */
                        cout << "Choose ID to Chang Status OK: ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            data[numberinputId][6] = "KO";
                            cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][6] << endl;

                            checkinptID = 1;
                            cheackCase = 1;

                            write_file();
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '2':
        {
            // display ราย เเละ ถ้าต้องการเเก้ใขค่า Confirmation ให้เป็น
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                   Confirmation of acceptance                       *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Status" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][7] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit *Confirmation of Acceptance* Status!" << endl;
                cout << "Yse (1) or No (0)" << endl;
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {
                        /* code */
                        cout << "Choose ID to Chang Status OK: ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            data[numberinputId][7] = "YES";
                            cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][7] << endl;

                            checkinptID = 1;
                            cheackCase = 1;

                            write_file();
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '3':
        {
            // display  รายการ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                   Route and trip management                       *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Status" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][8] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit *Route and trip management* Trip!" << endl;
                cout << "Yse (1) or No (0): ";
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {

                        cout << "Choose ID to Chang Status OK: ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            char cheackCaseinput = 0;
                            /* code */
                            while (cheackCaseinput == 0)
                            {
                                cout << "===================================" << endl;
                                cout << "(1) Arip A Company Truck " << endl;
                                cout << "(2) Arip B Airplane " << endl;
                                cout << "(3) Arip C Kerry Express Thailand" << endl;
                                cout << "===================================" << endl;

                                cin >> cheackCaseinput;
                                switch (cheackCaseinput)
                                {

                                case '1':
                                    /* code */
                                    cout << "(1) Arip A Company Truck " << endl;
                                    data[numberinputId][8] = "Company Truck";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][8] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    write_file();
                                    cheackCaseinput = 1;

                                    break;
                                case '2':
                                    cout << "(2) Arip B Airplane " << endl;
                                    data[numberinputId][8] = "Airplane";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][8] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();

                                    break;
                                case '3':

                                    cout << "(3) Arip C Kerry Express Thailand" << endl;
                                    data[numberinputId][8] = "Kerry";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][8] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();
                                    break;

                                default:
                                    cout << "Enter 1 or  2 or 3 Only!!" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '4':
        {
            // display  รายการ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                   Receipt confirmation system                       *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Status" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][9] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit *Receipt confirmation system* Status!" << endl;
                cout << "Yse (1) or No (0): ";
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {
                        /* code */
                        cout << "Choose ID to Chang Status Confirm : ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            data[numberinputId][9] = "Confirm";
                            cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][9] << endl;

                            checkinptID = 1;
                            cheackCase = 1;

                            write_file();
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '5':
        {
            // display  รายการ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                        Destination                                 *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Status" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][12] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit * Payment collection* Status!" << endl;
                cout << "Yse (1) or No (0): ";
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {
                        /* code */
                        cout << "Choose ID to Chang Status Payment  : ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            data[numberinputId][10] = "Payment";
                            cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][10] << endl;

                            checkinptID = 1;
                            cheackCase = 1;

                            write_file();
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '6':
        {
            // display  รายการ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                           Source                                   *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(20) << "Source" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(20) << data[i][11] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit *Source* " << endl;
                cout << "Yse (1) or No (0): ";
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {

                        cout << "Choose ID to Chang Source.: ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            char cheackCaseinput = 0;
                            /* code */
                            while (cheackCaseinput == 0)
                            {
                                cout << "===================================" << endl;
                                cout << "(1) Source Chiang Mai " << endl;
                                cout << "(2) Source Bangkok " << endl;
                                cout << "(3) Source NAN" << endl;
                                cout << "===================================" << endl;
                                cout << "Enter Numbewr to Edit Source: ";
                                cin >> cheackCaseinput;
                                switch (cheackCaseinput)
                                {

                                case '1':
                                    /* code */
                                    cout << "(1) Source Chiang Mai " << endl;

                                    data[numberinputId][11] = "Chiang Mai";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][11] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    write_file();
                                    cheackCaseinput = 1;

                                    break;
                                case '2':
                                    cout << "(2) Source Bangkok " << endl;
                                    data[numberinputId][11] = "Bangkok";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][11] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();

                                    break;
                                case '3':

                                    cout << "(3) Source Nan" << endl;
                                    data[numberinputId][11] = "Nan";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][11] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();
                                    break;

                                default:
                                    cout << "Enter 1 or  2 or 3 Only!!" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '7':
        {
            // displayราย เเละ
            cout << "----------------------------------------------------------------------" << endl;
            cout << "===============    Inventory Transfers  MENU    ======================" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "*                           Destination                                   *" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << setw(5) << "ID" << setw(10) << "CodeID" << setw(10) << "Name" << setw(10) << "Destination" << endl;

            for (int i = 1; i < recordNumber; i++)
            {
                cout << setw(5) << data[i][0] << setw(10) << data[i][1] << setw(10) << data[i][2] << setw(10) << data[i][12] << endl;
            }
            bool cheackCase = 0;
            while (cheackCase == 0)
            {

                cout << "Do You want to edit *Destination* " << endl;
                cout << "Yse (1) or No (0): ";
                char input;
                cin >> input;
                switch (input)
                {
                case '0':
                {
                    cheackCase = 1;
                }

                break;
                case '1':
                {
                    bool checkinptID = 0;
                    while (checkinptID == 0)
                    {

                        cout << "Choose ID to Chang Source.: ";
                        int numberinputId;
                        cin >> numberinputId;

                        if (numberinputId >= 1 && numberinputId < recordNumber)
                        {
                            char cheackCaseinput = 0;
                            /* code */
                            while (cheackCaseinput == 0)
                            {
                                cout << "===================================" << endl;
                                cout << "(1) Destination Chiang Mai " << endl;
                                cout << "(2) Destination Bangkok " << endl;
                                cout << "(3) Destination NAN" << endl;
                                cout << "===================================" << endl;

                                cin >> cheackCaseinput;
                                switch (cheackCaseinput)
                                {

                                case '1':
                                    /* code */
                                    cout << "(1) Destination Chiang Mai " << endl;

                                    data[numberinputId][12] = "Chiang Mai";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][12] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    write_file();
                                    cheackCaseinput = 1;

                                    break;
                                case '2':
                                    cout << "(2) Destination Bangkok " << endl;
                                    data[numberinputId][11] = "Airplane";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][12] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();

                                    break;
                                case '3':

                                    cout << "(3) Destination Nan" << endl;
                                    data[numberinputId][11] = "Kerry";
                                    cout << setw(5) << data[numberinputId][0] << setw(10) << data[numberinputId][1] << setw(10) << data[numberinputId][2] << setw(10) << data[numberinputId][12] << endl;
                                    checkinptID = 1;
                                    cheackCase = 1;
                                    cheackCaseinput = 1;
                                    write_file();
                                    break;

                                default:
                                    cout << "Enter 1 or  2 or 3 Only!!" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Enter number Only!! again" << endl;
                        }
                    }
                }
                break;

                default:
                    cout << "Pless Enter Number (0) or (1)" << endl;
                    break;
                }
            }
        }
        break;
        case '8':
        {
            Report();
        }
        break;
        default:
            cout << "----------------------------------------------------------------------\n";
            cout << "-------------------X X X X X X X X -----------------------------------\n";
            cout << "You in put wront!! " << endl;
            cout << "Enter Numbere again" << endl;
            cout << "----------------------------------------------------------------------\n";
            break;
        }
    }
}

void Unitofmeasurement()
{
    bool checking = 0;
    while (checking == 0)
    {

        cout << "----------------------------------------------------------------------" << endl;
        cout << "=============      Unit Of Measurement  MENU  =======================" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "*                   (1) Single Unit                                  *" << endl;
        cout << "*                   (2) Multiple Unit                                *" << endl;
        cout << "*                   (0) END Documenting  MENU                        *" << endl;
        cout << "----------------------------------------------------------------------\n";
        char input;
        cout << "You want to change the mode of Unit?" << endl;
        cout << "Enter number : ";
        cin >> input;
        switch (input)
        {
        case '0':
        {
            checking = 1;
        }
        break;
        case '1':
        {
            cout << "Change Mode to Single Unit ." << endl;
            cout << "DONE" << endl;
            cout << "======================================================================\n";
            modeprogramUnit = "Single Unit";
            checking = 1;
        }

        break;
        case '2':
        {
            cout << "Change Mode to Multiple Unit." << endl;
            cout << "DONE" << endl;
            cout << "======================================================================\n";
            modeprogramUnit = "Multiple Unit";
            checking = 1;
        }

        default:
            cout << "----------------------------------------------------------------------\n";
            cout << "-------------------X X X X X X X X -----------------------------------\n";
            cout << "You in put wront!! " << endl;
            cout << "Enter Numbere again" << endl;
            cout << "----------------------------------------------------------------------\n";
            break;
        }
    }
}

bool login()
{
    string username;
    string password;
    int count = 0;
    while (true)
    {
        cout << "**********************************************************************" << endl;
        cout << "***********    Welcome to  Warehouse Management System     ***********" << endl;
        cout << "**********************************************************************" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                       Login System                                 *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "**********************************************************************" << endl;
        cout << "Enter UserName: ";
        cin >> username;
        cout << "Ente  PassWrod: ";
        cin >> password;

        if (username == "admin" && password == "pass")
        {
            return 0;
        }
        else
        {
            cout << "UserName or Passworld Wrong :P" << endl;
        }

        if (count == 4)
        {
            cout << "Enter passworld  > 4 :P " << endl;
            return 1;
        }
        count++;
    }
}

void displayMenusystem()
{
    cout << "**********************************************************************" << endl;
    cout << "***********    Welcome to  Warehouse Management System     ***********" << endl;
    cout << "**********************************************************************" << endl;
    // chack program is start on
    bool startprogram = 0;
    while (startprogram == 0)
    {
        char input;

        cout << "----------------------------------------------------------------------" << endl;
        cout << "======================     MENU     ==================================" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "*                   (1) Stock Entry                                  *" << endl;
        cout << "*                   (2) Documenting                                  *" << endl;
        cout << "*                   (3) Inventory Management                         *" << endl;
        cout << "*                   (4) Inventory Transfers                          *" << endl;
        cout << "*                   (5) Unit of measurement                          *" << endl;
        cout << "*                   (6) Report                                       *" << endl;
        cout << "*                   (0) END Program                                  *" << endl;
        cout << "----------------------------------------------------------------------\n";

        // user input

        cout << "Enter number(0 - 6) to go System : ";
        cin >> input;

        // give user enter  number  to go sytem
        switch (input)
        {
            // if user  exrite program
        case '0':
            cout << "your wont to exeit program!" << endl;
            cout << "Yes/No (y/n) : ";
            char enter;
            cin >> enter;
            if (enter == 'y')
            {
                startprogram = 1;
                cout << "Good bye see you again :)  " << endl;
                cout << "===================  End Program  ===================" << endl;
                system("Pause");
            }
            else
            {
                system("cls");
            }

            break;

        case '1':

            system("cls");
            StockEntry();

            break;
        case '2':
            system("cls");
            Documenting();
            system("cls");

            break;
        case '3':
            system("cls");
            InventoryManagement();
            system("cls");

            break;
        case '4':
            // Transportation Management System Menu
            system("cls");
            InventoryTransfers();
            system("cls");

            break;
        case '5':
            // Inventory Transfers menu
            system("cls");

            Unitofmeasurement();

            system("cls");

            break;
        case '6':
            // report function
            system("cls");

            Report();

            break;

        default:
            cout << "You input wrong!! " << endl;
            cout << "Plaes Enter number (0-7) only" << endl;
            system("pause");
            break;
        }
    }
}

// add data to Array
// โลดข้อ มูลจาก ไฟล์ข้อมูลเข้ามา เเละ เพิ่มเข้าไปใน array  Data
void adddata()
{
    ifstream in(filename.c_str());

    string line, field;

    vector<vector<string>> array; // the 2D array
    vector<string> v;             // array of values for one line only

    while (getline(in, line)) // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss, field, ',')) // break line into comma delimitted fields
        {
            v.push_back(field); // add each field to the 1D array
        }

        array.push_back(v); // add the 1D array to the 2D array
    }

    // print out what was read in

    for (size_t i = 0; i < array.size(); ++i)
    {
        for (size_t j = 0; j < array[i].size(); ++j)
        {
            data[i][j] = array[i][j]; // (separate fields by |)
        }

        // add recorenumber  ++
        recordNumber++;
    }

    in.close();
}

// start projram
int main(int argc, char const *argv[])
{
    // this ok
    if (login() == 0)
    {
        system("cls");

        // load data in file  to Array data
        adddata();
        // Menu Ststem
        displayMenusystem();
    }
    else
    {

        // End Program
        cout << "End Program " << endl;
    }

    return 0;
}