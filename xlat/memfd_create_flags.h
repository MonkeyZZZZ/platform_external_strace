/* Generated by ./xlat/gen.sh from ./xlat/memfd_create_flags.in; do not edit. */

static const struct xlat memfd_create_flags[] = {
#if !(defined(MFD_CLOEXEC) || (defined(HAVE_DECL_MFD_CLOEXEC) && HAVE_DECL_MFD_CLOEXEC))
# define MFD_CLOEXEC 1
#endif
 XLAT(MFD_CLOEXEC),
#if !(defined(MFD_ALLOW_SEALING) || (defined(HAVE_DECL_MFD_ALLOW_SEALING) && HAVE_DECL_MFD_ALLOW_SEALING))
# define MFD_ALLOW_SEALING 2
#endif
 XLAT(MFD_ALLOW_SEALING),
 XLAT_END
};