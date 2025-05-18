program p443;
{
	@JUDGE_ID: 20044WC 443 PASCAL "Ugly"
}
const
	hc : array[1..4] of byte = ( 2,3,5, 7);
var
	i,j,k : longint;
	w : array[0..5842] of longint;
	a : array[1..4] of longint;
	e : longint;
	n : longint;
begin
	fillchar(a,sizeof(a),0);
	fillchar(w,sizeof(w),0);
	w[0] := 1;
	for i := 1 to 5842 do begin
		e := 2147483647;
		for j := 1 to 4 do begin
			if w[a[j]]*hc[j] < e then e := w[a[j]]*hc[j];
		end;
		for j := 1 to 4 do begin
			if w[a[j]]*hc[j] = e then begin
				w[i] := e;
				inc(a[j]);
			end;
		end;
	end;

	while not eof do begin
		readln(n);
		if n = 0 then break;
		write('The ',n);
		if (n mod 10 > 3) or (n mod 10 = 0) then begin
			write('th');
		end else begin
			if ((n mod 100) div 10) = 1 then begin
				write('th');
			end else begin
				if n mod 10 = 1 then write('st');
				if n mod 10 = 2 then write('nd');
				if n mod 10 = 3 then write('rd');
			end;
		end;
		writeln(' humble number is ', w[n-1], '.');
	end;
end.
