#!/usr/bin/perl
#used sed command (sed 's/^Image:.*\.png$//g' PokemonFile151.txt > PokemonFileImageRmed.txt) to create below file

# used perl -pe 's/^[[:space:]]$/\n/g' PokemonFileImageRmed.txt > PokemonFileImageRmedSpaceAdded.txt to add extra spaces to clobber

my $name;
my $writefile="PokemonFile.txt" or die;
my $readfile="PokemonFileImageRmedSpaceAdded.txt" or die;
open(WRITEFILE,">>$writefile");
open(READFILE,"+<$readfile");
while(<READFILE>){
	$line=$_;
	print WRITEFILE $line;
	if($line=~m/Name:/){
		my @nameArray=split(" ",$line);
		$name=@nameArray[1];
	}
	if($line=~m/EvolveLvl:/){
		my $newLine1="UserSprite: User";
		my $newLine2="OppSprite: Opp";
		print WRITEFILE $newLine1.$name."\n";
		print WRITEFILE $newLine2.$name."\n";
		
	}
}
