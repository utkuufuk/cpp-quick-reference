#ifndef CONTACTINFO_H
#define CONTACTINFO_H

// required for strlen and strcpy functions
#include <cstring>

class ContactInfo
{
    private:
        char* name;
        char* phone;

    public:
        ContactInfo(char* n, char* p)
        { 
            // allocate just enough memory for the name and phone number
            name = new char[strlen(n) + 1];
            phone = new char[strlen(p) + 1];

            // copy the name and phone number to the allocated memory
            strcpy(name, n);
            strcpy(phone, p); 
        }

        // copy constructor (const protects the argument object against modification)
        ContactInfo(const ContactInfo &obj)
        {
            int nameSize = strlen(obj.name) + 1;
            int phoneSize = strlen(obj.phone) + 1;

            name = new char[nameSize];
            phone = new char[phoneSize];

            strcpy(name, obj.getName());
            strcpy(phone, obj.getPhoneNumber());
        }
        
        // destructor
        ~ContactInfo()
        { 
            delete [] name;
            delete [] phone; 
        }

        // const prevents any code calling the function from changing the name
        const char* getName() const
        {
            return name; 
        }

        const char* getPhoneNumber() const
        {
            return phone; 
        }
};
#endif