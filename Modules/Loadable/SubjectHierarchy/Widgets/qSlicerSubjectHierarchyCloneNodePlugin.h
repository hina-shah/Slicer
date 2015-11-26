/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __qSlicerSubjectHierarchyCloneNodePlugin_h
#define __qSlicerSubjectHierarchyCloneNodePlugin_h

// SubjectHierarchy Plugins includes
#include "qSlicerSubjectHierarchyAbstractPlugin.h"

#include "qSlicerSubjectHierarchyModuleWidgetsExport.h"

class qSlicerSubjectHierarchyCloneNodePluginPrivate;
class vtkMRMLNode;
class vtkMRMLScalarVolumeNode;
class vtkMRMLSubjectHierarchyNode;

// Due to some reason the Python wrapping of this class fails, therefore
// put everything between BTX/ETX to exclude from wrapping.
// TODO investigate why the wrapping fails:
//   https://www.assembla.com/spaces/slicerrt/tickets/210-python-wrapping-error-when-starting-up-slicer-with-slicerrt
//BTX

/// \ingroup Slicer_QtModules_SubjectHierarchy_Widgets
class Q_SLICER_MODULE_SUBJECTHIERARCHY_WIDGETS_EXPORT qSlicerSubjectHierarchyCloneNodePlugin : public qSlicerSubjectHierarchyAbstractPlugin
{
public:
  Q_OBJECT

public:
  typedef qSlicerSubjectHierarchyAbstractPlugin Superclass;
  qSlicerSubjectHierarchyCloneNodePlugin(QObject* parent = NULL);
  virtual ~qSlicerSubjectHierarchyCloneNodePlugin();

public:
  Q_INVOKABLE static const QString getCloneNodeNamePostfix() { return QString(" Copy"); };

public:
  /// Get node context menu item actions to add to tree view
  Q_INVOKABLE virtual QList<QAction*> nodeContextMenuActions()const;

  /// Show context menu actions valid for  given subject hierarchy node.
  /// \param node Subject Hierarchy node to show the context menu items for. If NULL, then shows menu items for the scene
  virtual void showContextMenuActionsForNode(vtkMRMLSubjectHierarchyNode* node);

public:
  /// Clone a subject hierarchy node along with its associated data node, and its display and storage nodes.
  /// \param node Subject Hierarchy node to clone
  /// \param name Name of the cloned node (optional; if omitted it will be postfixed with "_Clone")
  /// \return The cloned subject hierarchy node
  Q_INVOKABLE vtkMRMLSubjectHierarchyNode* cloneSubjectHierarchyNode(vtkMRMLSubjectHierarchyNode* node, QString name=QString());

protected slots:
  /// Clone currently selected subject hierarchy entry and associated data node
  void cloneCurrentNode();

protected:
  QScopedPointer<qSlicerSubjectHierarchyCloneNodePluginPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerSubjectHierarchyCloneNodePlugin);
  Q_DISABLE_COPY(qSlicerSubjectHierarchyCloneNodePlugin);
};

//ETX

#endif
