/* Generated by ./xlat/gen.sh from ./xlat/epollctls.in; do not edit. */

static const struct xlat epollctls[] = {
#if !(defined(EPOLL_CTL_ADD) || (defined(HAVE_DECL_EPOLL_CTL_ADD) && HAVE_DECL_EPOLL_CTL_ADD))
# define EPOLL_CTL_ADD 1
#endif
 XLAT(EPOLL_CTL_ADD),
#if !(defined(EPOLL_CTL_DEL) || (defined(HAVE_DECL_EPOLL_CTL_DEL) && HAVE_DECL_EPOLL_CTL_DEL))
# define EPOLL_CTL_DEL 2
#endif
 XLAT(EPOLL_CTL_DEL),
#if !(defined(EPOLL_CTL_MOD) || (defined(HAVE_DECL_EPOLL_CTL_MOD) && HAVE_DECL_EPOLL_CTL_MOD))
# define EPOLL_CTL_MOD 3
#endif
 XLAT(EPOLL_CTL_MOD),
 XLAT_END
};
