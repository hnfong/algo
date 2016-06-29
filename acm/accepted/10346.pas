program p10346;
{
@JUDGE_ID:  20044WC 10346 PASCAL "Siliconism - LFM"
}
var
	n,k : longint;
begin
	while not eof do begin
		readln(n,k);
		if n <= 0 then begin writeln(n); continue; end;
		if ( (n*k) mod (k-1) ) > 0 then begin writeln( (n*k) div (k-1) ); continue; end;
		if ( (n*k) mod (k-1) ) = 0 then begin writeln( (n*k) div (k-1) - 1); continue; end;
	end;
end.
