#pragma once

namespace Brisk{

    class Layer{

        public:
            virtual void onAttach();
            virtual void onDetach();
            virtual void onUpdate();
        protected:
            virtual void onEvent();

    };

}