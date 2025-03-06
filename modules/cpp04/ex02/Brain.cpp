#include "Brain.hpp"

Brain::Brain( void )
{
	ideas[0] = "I'm hungry for meat";
        ideas[1] = "I want to play fetch";
        ideas[2] = "Nap time sounds nice";
        ideas[3] = "I could use a belly rub";
        ideas[4] = "Let's chase the laser pointer";
        ideas[5] = "I need to go outside";
        ideas[6] = "A walk would be amazing";
        ideas[7] = "I want a cozy blanket";
        ideas[8] = "Where's my favorite toy?";
        ideas[9] = "Can we cuddle?";
        ideas[10] = "I think I saw a squirrel";
        ideas[11] = "Scratches behind the ears, please";
        ideas[12] = "What’s in the fridge?";
        ideas[13] = "Time to stretch my paws";
        ideas[14] = "I smell something delicious";
        ideas[15] = "I’m ready for a game of tug-of-war";
        ideas[16] = "Can we explore the backyard?";
        ideas[17] = "Did you hear that sound?";
        ideas[18] = "A sunny spot to nap sounds perfect";
        ideas[19] = "I hope it’s treat time soon";
        ideas[20] = "What’s under the couch?";
        ideas[21] = "I feel like digging a hole";
        ideas[22] = "I want to climb up high";
        ideas[23] = "How about a warm lap to sit on?";
        ideas[24] = "I’m dreaming of chasing birds";
        ideas[25] = "Time to patrol my territory";
        ideas[26] = "I love head scratches";
        ideas[27] = "Can we visit the park today?";
        ideas[28] = "I’d like a big bowl of water";
        ideas[29] = "It’s grooming time";
        ideas[30] = "I heard a doorbell!";
        ideas[31] = "Is it time for dinner?";
        ideas[32] = "I think I’ll stare out the window";
        ideas[33] = "I want to sniff everything";
        ideas[34] = "I’m curious about that box";
        ideas[35] = "Let’s watch TV together";
        ideas[36] = "I want to chase my tail";
        ideas[37] = "I think there’s a bug in the house";
        ideas[38] = "I’d like to chew on a bone";
        ideas[39] = "What’s that shiny thing?";
        ideas[40] = "I hope it’s bedtime soon";
        ideas[41] = "I need to scratch something";
        ideas[42] = "I’m feeling a little mischievous";
        ideas[43] = "Let’s sniff some flowers";
        ideas[44] = "I heard the food bag crinkle!";
        ideas[45] = "I want to chase a ball";
        ideas[46] = "Is that a catnip toy?";
        ideas[47] = "Time to clean my paws";
        ideas[48] = "Let’s dig into the sand";
        ideas[49] = "I need to mark my favorite spot";
        ideas[50] = "I’m ready for hide and seek";
        ideas[51] = "I think I’ll roll in the grass";
        ideas[52] = "What’s that new smell?";
        ideas[53] = "I could climb a tree right now";
        ideas[54] = "I’d like a new squeaky toy";
        ideas[55] = "Do you have a warm blanket?";
        ideas[56] = "I think I’ll lie on your keyboard";
        ideas[57] = "Time for a midnight snack";
        ideas[58] = "I think it’s bath time";
        ideas[59] = "Let’s go for an adventure";
        ideas[60] = "I hope you’re bringing treats";
        ideas[61] = "I want to sit on the windowsill";
        ideas[62] = "Time to pounce on something";
        ideas[63] = "Can we chase butterflies?";
        ideas[64] = "I think I saw another animal outside";
        ideas[65] = "I want to follow you everywhere";
        ideas[66] = "What’s that under the bed?";
        ideas[67] = "I’m feeling playful right now";
        ideas[68] = "I love the sound of crinkling paper";
        ideas[69] = "Time to watch the world go by";
        ideas[70] = "I need some quiet time";
        ideas[71] = "Let’s scratch the post";
		std::cout << std::endl;
        ideas[72] = "I’d like a tasty fish treat";
        ideas[73] = "I think I hear a bird chirping";
        ideas[74] = "How about a nap on the couch?";
        ideas[75] = "Let’s play in the yard";
        ideas[76] = "I love when you call my name";
        ideas[77] = "Can we jump in the leaves?";
        ideas[78] = "I need to find my hiding spot";
        ideas[79] = "Let’s share some love";
        ideas[80] = "I’m dreaming of running free";
        ideas[81] = "I want to curl up by the fire";
        ideas[82] = "What’s on the other side of the fence?";
        ideas[83] = "I’m looking for my favorite snack";
        ideas[84] = "How about a bedtime story?";
        ideas[85] = "Let’s find some shade";
        ideas[86] = "I need to jump over something";
        ideas[87] = "How about a new adventure?";
        ideas[88] = "I want to learn a new trick";
        ideas[89] = "Let’s find a sunny spot";
        ideas[90] = "I’m ready for some love and attention";
        ideas[91] = "Can we sniff around together?";
        ideas[92] = "I want to climb onto something high";
        ideas[93] = "Let’s chase each other";
        ideas[94] = "I’m thinking of purring loudly";
        ideas[95] = "I could wag my tail all day";
        ideas[96] = "Time to explore every corner";
        ideas[97] = "I’m watching you closely";
        ideas[98] = "I need to sit in a box";
        ideas[99] = "Let’s be best friends forever";
	std::cout << MAGENTA << "Brain default CONStructor called."
		<< RESET << std::endl;
}

Brain::Brain(const Brain& to_copy) 
{	
	*this = to_copy; 	
	std::cout << MAGENTA << "Brain copy construtor called."
		<< RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& to_copy)
{
	if (this != &to_copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = to_copy.ideas[i];
	}
	std::cout << MAGENTA << "Brain copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Brain::~Brain( void )
{
	std::cout << MAGENTA << "Brain default DEStructor called."
		<< RESET << std::endl;
}

