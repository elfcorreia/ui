#include <string>
#include <string_view>

namespace ui {

    class dialog {            
    public:        
        struct platform {
            void show(ui::dialog* dialog);
        };
        void* platform_data() { return _platform_data; }
        void* set_platform_data(void* value) { return _platform_data = value; }
        
        void set_title(const std::string& title) {
            _title = title;
        }
        std::string title() {
            return _title;
        }
        void show() {
            _platform.show(this);
        }
    private:
        void* _platform_data;
        platform _platform;
        std::string _title;
    };
}