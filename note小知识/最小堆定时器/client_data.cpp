
#include <cstring>

class client_data
{
public:
    client_data(char *address):target_count(0)
    {
        strcpy(ip_address,address);
    }
private:
    char ip_address[32];
    target target_list[64];
    int target_count;
};