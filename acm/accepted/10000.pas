program p10000;
{
	@JUDGE_ID:  20044WC 10000 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	n : longint;
	a, b :longint;
	w : array[1..100,1..100] of byte;
	h,t : longint;
	f : longint;
	mi : longint;
begin
	mi := 0;
	while not eof do begin
	inc(mi);
	readln(n);
	if n = 0 then break;
	readln(h);
	fillchar(w,sizeof(w),0);
	
	while true do begin
		readln(a,b);
		if (a=0) or (b=0) then break;
		w[a,b] := 1;
	end;
	for k := 1 to n do begin
		for i := 1 to n do begin
			for j := 1 to n do begin
				if (i=k) or (k=j) or (i=j) then continue; { avoid cyclic }
				if (w[i,k]+w[k,j] > w[i,j]) and (w[i,k]>0) and (w[k,j]>0) then begin
					w[i,j] := w[i,k]+w[k,j];
				end;
			end;
		end;
	end;
	f := 0;
	for i := 1 to n do begin
		if w[h,i] > f then begin
			f := w[h,i];
			t := i;
		end;
	end;
	writeln('Case ',mi,': The longest path from ',h,' has length ',f,', finishing at ',t,'.');
	writeln;
	end;
end.

