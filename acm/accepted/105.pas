program p105;
{
	@JUDGE_ID:  20044WC 105 PASCAL "Data Structures"
	Actually should be: Low B Data Structures
}
var
	i,j,k : longint;
	a : array[0..10000] of longint;
	e,h,f : longint;
function max(a,b:longint) : longint;
begin
	if a > b then max := a else max := b;
end;
begin
	fillchar(a,sizeof(a),0);
	while not eof do begin
		readln(e,h,f);
		for i := e to f-1 do begin
			a[i] := max(a[i],h);
		end;
	end;
	h := 0;
	k := 0;
	for i := 1 to 10000 do begin
		if a[i] <> h then begin
			h := a[i];
			if k = 0 then write(i, ' ',h) else write(' ', i, ' ', h);
			k := 1;
		end;
	end;writeln;
end.
