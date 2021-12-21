void        display_error(const t_errors error)
{
        const char        *error_msgs[INVALID] = {
                "usage: ./so_long [ .ber mapfile ]",
                "map file must have a .ber extension",
                "map is not rectangular in shape",
                "map is not enclosed by walls",
                "map must have at least one exit",
                "map must have a starting position for the player",
                "map must have at least one collectible",
                "multiple starting positions exists on the map",
                "a malloc error has occurred.",
        };
        printf("%s\n", error_msgs[error]);
        exit(EXIT_FAILURE);
}
