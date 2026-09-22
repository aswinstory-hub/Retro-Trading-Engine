#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/ftxui.hpp>
#include <ftxui/screen/color.hpp>
#include <string>
#include <vector>

#include "main.hpp" 
#include "ftxui/dom/elements.hpp"


using namespace ftxui;



int main() {
 
    auto screen = ScreenInteractive::TerminalOutput();

    // State
    Page page = Page::Charting;


    // Components
    auto watchlist = vbox() | size(HEIGHT, EQUAL, 18);
    auto indicator = vbox() | flex ; 
    auto chart = vbox() | flex;
    auto guide = vbox();

    
    auto renderer = Renderer( [&] {

        auto charting =
            hbox({

                // Left Side 
                vbox({
                    // Title
                    hbox({ text("Charting") }) | border,
                                                

                    // Watchlist
                    window(text(" Watchlist "), watchlist),
                    
                    // Indicator
                    window(text(" Indicators "), indicator),
                })
                | size(WIDTH, EQUAL, 25)
                | size(HEIGHT, EQUAL, 200),

                // Right side
                vbox({

                    // Ticker And LTP
                    hbox({ text("Ticker"), filler(), text("LTP") }) | border ,

                    window(text(" Chart "), chart),

                    window(text(" Guide "), guide),
                }) | flex  
                
            });

        return charting;
                           
    });




    auto app = CatchEvent(renderer, [&](Event event) {

        if (event == Event::Character('q')) {
            screen.Exit();
            return true;
        }
        return false;                          
    });

    screen.Loop(app);  
}
 
