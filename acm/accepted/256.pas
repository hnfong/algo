program p256;
{
	@JUDGE_ID: 20044WC 256 PASCAL "HC"
}
var n : longint;
begin
	while not eof do begin
		readln (n);
		if n = 8 then begin
			writeln('00000000');
			writeln('00000001');
			writeln('04941729');
			writeln('07441984');
			writeln('24502500');
			writeln('25502500');
			writeln('52881984');
			writeln('60481729');
			writeln('99980001');
		end;
		if n = 6 then begin
			writeln('000000');
			writeln('000001');
			writeln('088209');
			writeln('494209');
			writeln('998001');
		end;
		if n = 4 then begin
			writeln('0000');
			writeln('0001');
			writeln('2025');
			writeln('3025');
			writeln('9801');
		end;
		if n = 2 then begin
			writeln('00');
			writeln('01');
			writeln('81');
		end;
	end;
end.
