program p10220;
{
	@JUDGE_ID: 20044WC 10220 PASCAL "HPA"
}
var
	i,j,k : longint;
	w : array[1..3000] of integer;
	n : longint;
	z : longint;
	ans : array[1..1000] of longint;
begin
	fillchar(w,sizeof(w),0);
	w[1] := 1;
	for i := 1 to 1000 do begin
		for j := 1 to 3000 do begin
			w[j] := w[j] * i;
		end;
		
		k := 0;
		for j := 1 to 3000 do begin
			w[j] := w[j] + k;
			k := w[j] div 10;
			w[j] := w[j] mod 10;
		end;

		z := 0;
		for j := 1 to 3000 do begin
			z := z + w[j];
		end;

		ans[i] := z;
	end;
	while not eof do begin
		readln(n);
		writeln(ans[n]);
	end;
end.
