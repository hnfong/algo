program p1030;
var
	i,j,k,n : longint;
	w : array[0..1010] of longint;
	writ : boolean;
	r : longint;
function nex(x : longint) : longint;
var t : longint;
begin
	t := (x + r) mod n;
	while w[t] = 0 do begin
		inc(t);
		t := t mod n;
	end;
	nex := t;
end;

begin
	fillchar(w,sizeof(w),1);
	readln(n);
	r := 1;
	j := 0;
	writ := false;
	while j <> nex(j) do begin
		k := nex(j);
		if k < j then inc(r);
		if not writ then begin
			write(k+1);
			writ := true;
		end else begin
			write(' ', k+1);
		end;
		w[k] := 0;
		j := nex(k);
	end;
	writeln;
	writeln(j+1);
end.
