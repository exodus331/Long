class SoooLong
{
public:
        unsigned char *number;
        int size;
        unsigned char sign;
        SoooLong();
        SoooLong(const SoooLong &);
        ~SoooLong();
        int read(char*);
        int output(char*);
        SoooLong operator+(SoooLong );
        SoooLong operator-(SoooLong );
        SoooLong operator*(SoooLong );
        SoooLong operator/(SoooLong );
        SoooLong operator%(SoooLong );
        SoooLong operator^(SoooLong );
        SoooLong operator=(SoooLong );
        SoooLong operator=(const char*);
        bool operator==(SoooLong );
        bool operator<(SoooLong );
        bool operator>(SoooLong );
private:
        int MyStrlen(unsigned char**);
};
