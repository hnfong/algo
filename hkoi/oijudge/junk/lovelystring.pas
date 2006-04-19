program plovely;
const
	v : array['A'..'Z'] of longint = (
	1,2,3,4,5,6,7,8,9,10,
	11,12,13,14,15,16,17,18,19,20,
	21,22,23,24,25,26
	);
var
	i,j,k : longint;
	s : string;
	t,e : char;
procedure recur(c:char);
var e:char;
begin
	if c = t then begin
		writeln(s,t);
		exit;
	end;
	s := s + c;
	for e := 'A' to 'Z' do begin
		if 5*v[c]<=4*v[e] then recur(e);
	end;
	delete(s,length(s),1);
end;

begin
	s := '';
	readln(t);
	for e  := 'A' to 'Z' do begin 
		if e = t then break;
		recur(e);
	end;
end.
