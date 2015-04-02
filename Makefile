CC = g++
	

OH1:
	rootcint -f $(@)Dict.cxx -c include/$(@).hh LinkDef.h
	$(CC) `root-config --cflags --libs` -shared $(@)Dict.cxx src/$(@).cc -o lib/lib$(@).so -I include


OGraph:
	rootcint -f $(@)Dict.cxx -c include/$(@).hh LinkDef.h
	$(CC) `root-config --cflags --libs` -shared $(@)Dict.cxx src/$(@).cc -o lib/lib$(@).so -I include


#clean:
#	rm -rf $(TARGET) ./*~ $(OBJ) src/AnapawMode.cc aproot_dict.*

clean:
	rm lib/*.so O*Dict.cxx O*Dict.h

.PHONY: clean
