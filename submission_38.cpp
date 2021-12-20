void        Karen::complain(std::string level)
{
        int        index = (level == "DEBUG") * DEBUG_INDEX + (level == "INFO") * INFO_INDEX \
                        + (level == "WARNING") * WARNING_INDEX + (level == "ERROR") * ERROR_INDEX;
        (this->*comments[index])();
}
