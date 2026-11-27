
static void	set_prefix_dot_number(char *flag, char cspecifier,
		t_specifier *spec)
{
	int	nb_flag;

	ft_memset(spec->prefix.buffer, '0', 64);
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	set_prefix_lenvalue(flag, cspecifier, spec, nb_flag);
}

static void	set_prefix_dot(char *flag, char cspecifier, t_specifier *spec)
{
	int	nb_flag;

	if (ft_strchr("diuxXp", cspecifier))
		return (set_prefix_dot_number(flag, cspecifier, spec));
	nb_flag = ft_atoi(ft_strrchr(flag, '.') + 1);
	set_prefix_lenvalue(flag, cspecifier, spec, nb_flag);
}
