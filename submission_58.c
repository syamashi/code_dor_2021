size_t        ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        size_t        i;

        i = ft_strnlen(dst, dstsize);
        return (i + ft_strlcpy(dst + i, src, dstsize - i));
}
