# SFMLengine

руководство как что нибудь запустить на сыром движке

зайти в файл game.cpp
в конструкторе добавить объект(entity)
в entity добавить компоненты (entities[i].add_component(компонет который хотите добавить))

настроить компонент: entities[i].get<компонет для изменения *>()-> функция компонента

отрисовка - DrawComponent(сслыка на то что надо отрисовать)

также имеются компонеты:
-------------------
enum class Type
{
	component ,
	drawComponent,
	textureComponent,
	vertexComponent,
	bphysComponent,
	shapeComponent,
	colissionComponent,
	animationComponent
};
---------------------
интуитивно понятно что за что отвечает

движок продолжает разрабатываться так что скоро на нем уже можно будет писать полноцеенные 2д игры

чтобы добавить компонент надо создать класс и добавить родителя (class MyComponent: public Component),добавить в enum и прописать сценарии в ComponentStorage

пока что на этом все
