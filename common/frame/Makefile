frame.pb.h: frame.pb.c

frame.pb.c: frame.proto
	${NANOPB_BIN}/protoc --nanopb_out=. frame.proto
