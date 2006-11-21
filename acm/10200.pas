program x10200;
{
	@JUDGE_ID:  20044WC 10200 PASCAL "Siliconism"
}
var
	s : string;
	a, b : longint;
	i : longint;
	t : longint;
	dat : array[0..10000] of byte;
function isprime(x : longint) : boolean;
var i : longint; t : boolean;
begin
	t := true;

	for i := 2 to trunc(sqrt(x)) do begin
		if (x mod i) = 0 then begin t := false; break; end;
	end;

	isprime := t;
end;
begin
	fillchar(dat, 10001, 0);
	for i := 0 to 10000 do begin
		if isprime(i*i+i+41) then dat[i] := 1;
	end;
	while (not eof(input)) do begin
		readln(s);
		val(copy(s, 1, pos(' ', s) - 1), a, i);
		val(copy(s, pos(' ', s)+1, length(s) - pos(' ', s)+1), b, i);
		t := 0;
		for i := a to b do begin
			if (dat[i] = 1) then inc(t);
		end;
		writeln(t * 100 / (b-a+1):1:2);
	end;
end.

