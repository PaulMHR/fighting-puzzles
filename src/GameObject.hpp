// ts code
// export interface GameObject {
//     enabled : Bool;
//     draw() : void;
//     update(delta : number) : void;
// }

//cpp code
class GameObject {
    public:
        bool enabled;
        virtual void draw() = 0;
        virtual void update(int delta) = 0;
}
