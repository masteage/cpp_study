//
//  Grid.h
//  ch_21
//
//  Created by taeseongsong on 21/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#ifndef Grid_h
#define Grid_h

#if defined(_TEMPLATE_NORMAL_)
// template 2 - ch_21_1_1
template <typename T, typename Container>
#elif defined(_DEFAULT_TEMPLATE_TYPE_)
// default template - ch_21_1_1_1
template <typename T, typename Container = std::vector<T>>
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
//template <... , template <TemplateTypeParameters> class ParameterName, ...>
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container = std::vector>
//template <typename T, template <typename E, typename Allocator = std::allocator<E>> typename Container = std::vector>
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT = T()>
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
#endif	// _TEMPLATE_NORMAL_
class Grid
{
public:
	explicit Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	virtual ~Grid();
	
	// Sets an element at a given location. The element is copied.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	
	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;
	
private:
	void initializeCellsContainer();
#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
	std::vector<Container> mCells;
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
	std::vector<Container<T>> mCells;
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_) || defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
	std::vector<std::vector<T>> mCells;
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	size_t mWidth, mHeight;
};

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
Grid<T, Container>::Grid(size_t inWidth, size_t inHeight)
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
Grid<T, Container>::Grid(size_t inWidth, size_t inHeight)
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
Grid<T, DEFAULT>::Grid(size_t inWidth, size_t inHeight)
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
Grid<T, DEFAULT>::Grid(size_t inWidth, size_t inHeight)
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
: mWidth(inWidth), mHeight(inHeight){
	initializeCellsContainer();
}

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
Grid<T, Container>::~Grid(){
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
Grid<T, Container>::~Grid(){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
Grid<T, DEFAULT>::~Grid(){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
Grid<T, DEFAULT>::~Grid(){
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	// Nothing to do, the vector will clean up itself.
}

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
void Grid<T, Container>::initializeCellsContainer(){
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
void Grid<T, Container>::initializeCellsContainer(){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
void Grid<T, DEFAULT>::initializeCellsContainer(){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
void Grid<T, DEFAULT>::initializeCellsContainer(){
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		// not resize function container case
		// -> Member reference base type 'int' is not a structure or union
		column.resize(mHeight);
#ifdef _NON_TYPE_TEMPLATE_PARAMETER_
		for(auto& element : column){
			element = DEFAULT;
		}
#endif	// _NON_TYPE_TEMPLATE_PARAMETER_
	}
}

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
void Grid<T, Container>::setElementAt(size_t x, size_t y, const T& inElem){
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
void Grid<T, Container>::setElementAt(size_t x, size_t y, const T& inElem){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
void Grid<T, DEFAULT>::setElementAt(size_t x, size_t y, const T& inElem){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
void Grid<T, DEFAULT>::setElementAt(size_t x, size_t y, const T& inElem){
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	mCells[x][y] = inElem;
}

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
T& Grid<T, Container>::getElementAt(size_t x, size_t y){
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
T& Grid<T, Container>::getElementAt(size_t x, size_t y){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y){
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y){
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	return mCells[x][y];
}

#if defined(_TEMPLATE_NORMAL_) || defined(_DEFAULT_TEMPLATE_TYPE_)
template <typename T, typename Container>
const T& Grid<T, Container>::getElementAt(size_t x, size_t y) const{
#elif defined(_TEMPLATE_TEMPLATE_PARAMETER_)
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
const T& Grid<T, Container>::getElementAt(size_t x, size_t y) const{
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_)
template <typename T, const T DEFAULT>
const T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y) const{
#elif defined(_NON_TYPE_TEMPLATE_PARAMETER_REF_)
template <typename T, const T& DEFAULT>
const T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y) const{
#endif	// _TEMPLATE_NORMAL_ || _DEFAULT_TEMPLATE_TYPE_
	return mCells[x][y];
}

#endif /* Grid_h */
