size_t        ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        size_t        l;

        l = ft_strnlen(dst, dstsize);
        if (l == dstsize)
                return (l + ft_strlen(src));
        return (l + ft_strlcpy(dst + l, src, dstsize - l));
}
