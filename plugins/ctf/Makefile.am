AM_CFLAGS = $(PACKAGE_CFLAGS) -I$(top_srcdir)/include

SUBDIRS = common fs lttng-live

plugindir = "$(PLUGINSDIR)"
plugin_LTLIBRARIES = libbabeltrace-plugin-ctf.la

# ctf plugin
libbabeltrace_plugin_ctf_la_SOURCES = plugin.c

libbabeltrace_plugin_ctf_la_LDFLAGS = \
	-version-info $(BABELTRACE_LIBRARY_VERSION)

libbabeltrace_plugin_ctf_la_LIBADD = \
	$(top_builddir)/lib/libbabeltrace.la \
	$(top_builddir)/formats/ctf/libbabeltrace-ctf.la \
	fs/libbabeltrace-plugin-ctf-fs.la \
	lttng-live/libbabeltrace-plugin-ctf-lttng-live.la
