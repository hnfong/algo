program p1007;
type	packet = record
		i : longint;
		s : string;
	end;
var
	i,j,k,n,p,z : longint;
	w : array[0..99] of packet;
	in1 : string[3];
	in2 : string[2];
	in3 : string[4];
	in4 : string;
begin
	readln(n);
	while not eof do begin
		readln(in1,in2,in3,in4);
		val(in2, p, j);
		val(in1, w[p].i, j);
		w[p].s := in4;
	end;
	for i := 1 to n do write(w[i].s);
	writeln;
end.
