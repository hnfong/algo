program asdf;
const debug = false;
type data = array[1..2000000] of longint;
var
	i,j,k,s : longint;
	a,b,m : longint;
	w,v : data;
procedure csort(var a,b : data; x:longint);
var
	i,j,k : longint;
	c : array[0..65535] of longint;
	sh : longint;
begin
	fillchar(c,sizeof(c),0);
	sh := x * 4;
	for i := 1 to m do inc(c[(a[i] shr sh) and 65535 ]);
	for i := 1 to 65535 do c[i] := c[i]+c[i-1];
	for i := m downto 1 do begin
		b[c[a[i] shr sh and 65535]] := a[i];
		dec(c[a[i] shr sh and 65535]);
	end;
end;
begin
	readln(a,b,m,k);
	s := 0;
	for i := 1 to m do begin
		s := (s+a) mod b;
		w[i] := s;
	end;
	if debug then begin
		for i := 1 to m do begin write(w[i],' '); end; writeln;
	end;
	csort(w,v,0); csort(v,w,1); csort(w,v,2); csort(v,w,3);
	if debug then begin
		for i := 1 to m do write(v[i],' '); writeln;
	end;
	for i := 1 to k do begin
		readln(j) ;
		writeln(w[j]);
	end;
end.
