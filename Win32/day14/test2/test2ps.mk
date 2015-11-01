
test2ps.dll: dlldata.obj test2_p.obj test2_i.obj
	link /dll /out:test2ps.dll /def:test2ps.def /entry:DllMain dlldata.obj test2_p.obj test2_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del test2ps.dll
	@del test2ps.lib
	@del test2ps.exp
	@del dlldata.obj
	@del test2_p.obj
	@del test2_i.obj
