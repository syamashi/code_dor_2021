std::string myReplace(std::string str, std::string s1, std::string s2)
{
        int position;
        std::string front;
        std::string back;
        
        position = str.find(s1);
        if (pos == -1)
                return (str);
        front = str.substr(0, position) + s2;
        back = myReplace(str.substr(position + s1.length()), s1, s2);
        return (front + back);
}
