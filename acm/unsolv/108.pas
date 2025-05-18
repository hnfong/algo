program x108;
var
	dp : array[0..100, 0..100] of longint;
	map : array[0..100, 0..100] of longint;
	pro : array[0..100, 0..100] of longint;
	i,j,k : longint;
	n : longint;
procedure dump;
var
	i,j,k : longint;
begin
	for i := 1 to n do begin
		for j := 1 to n do begin
			write(pro[i,j]:4);
		end;
		writeln;
	end;
end;
function max(x,y:longint) : longint; begin if x > y then max := x else max := y; end;

begin
	fillchar(dp, sizeof(dp), 0);
	fillchar(pro, sizeof(pro), 0);
	fillchar(map, sizeof(map), 0);
	readln(n);
	for i := 1 to n do begin
		for j := 1 to n do begin
			read(map[i,j]);
		end;
	end;
	
	for i := 1 to n do begin
		pro[1,i] := map[1,i];
	end;
	for i := 2 to n do begin
		for j := 1 to n do begin
			if pro[i-1,j] < 0 then pro[i,j] := map[i,j] else pro[i,j] := pro[i-1,j] + map[i,j];
		end;
	end;

	dump;
end.

