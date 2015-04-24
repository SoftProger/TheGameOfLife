#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include "game.h"

class Application
{
    Game game;
    const std::string lifeQuotes[18] = {"Life isn't about finding yourself. Life is about creating yourself.",
                                      "Life is really simple, but we insist on making it complicated.",
                                     "Life is 10% what happens to us and 90% how we react to it.",
                                     "When I hear somebody sigh, ‘Life is hard,’ I am always tempted to ask, ‘Compared to what?’",
                                      "You only live once, but if you do it right, once is enough.",
                                      "Everything you can imagine is real.",
                                      "Life is like riding a bicycle. To keep your balance, you must keep moving.",
                                      "Life is a progress, and not a station.",
                                      "People living deeply have no fear of death.",
                                      "Life is the sum of all your choices.",
                                       "We do not see things as they are. We see them as we are.",
                                       "What would life be if we had no courage to attempt anything?",
                                       "Live every act fully, as if it were your last.",
                                       "Lord, let me live until I die.",
                                       "There are two great rules of life: never tell everything at once.",
                                       "Only a life lived for others is a life worthwhile.",
                                       "The purpose of life is a life of purpose.",
                                       "Life would be much easier if I had the source code."};
public:
    Application();
    void exec();
    ~Application();
};

#endif // APPLICATION_H
