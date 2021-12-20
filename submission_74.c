int        quotation_status(char c, int status)
{
        if (c == '\"')
        {
                if (status == IN_DOUBLE_QUOTE)
                        status = OUTSIDE;
                else if (status == IN_SINGLE_QUOTE)
                        status = IN_SINGLE_QUOTE;
                else
                        status = IN_DOUBLE_QUOTE;
        }
        else if (c == '\'')
        {
                if (status == IN_DOUBLE_QUOTE)
                        status = IN_DOUBLE_QUOTE;
                else if (status == IN_SINGLE_QUOTE)
                        status = OUTSIDE;
                else
                        status = IN_SINGLE_QUOTE;
        }
        return (status);
}
